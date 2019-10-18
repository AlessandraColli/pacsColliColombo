rm(list=objects())
graphics.off()

library(fdaPDE)

dimension<-"2.5"

path<-"~/Documents/ENSTA Paris 2A/PRe/Projet/fdaPDE/"

## WORKING DIRECTORY
setwd(paste(path,"RScripts/",dimension,"D Mesh/",sep=''))

## READ MESH
nodes<-as.matrix(read.csv("node.csv",sep=';',header=FALSE))
elems<-as.matrix(read.csv("elem.csv",sep=';',header=FALSE))
refElems<-as.matrix(read.csv("refElem.csv",sep=';',header=FALSE))

## DEFINE REGIONS
incidence_matrix<-matrix(0,nrow=3,ncol=nrow(elems))
incidence_matrix[1,refElems==2]<-1
incidence_matrix[2,refElems==3]<-1
incidence_matrix[3,refElems==4]<-1

## OBSERVATIONS, LOCATIONS AND COVARIATES
inside<-function(row,mat)
{
  found<-FALSE
  if (nrow(mat)>0){
    for (i in 1:nrow(mat)){
      for (j in 1:ncol(mat)){
        found<-TRUE
        if (row[j]!=mat[i,j]){
          found<-FALSE
          break
        }
      }
      if (found)
        break
    }
  }
  return(found)
}
z<-function(p)
{
  #sum(p)
  #exp(p[1])+3*p[1]*p[2]
  #cos(p[1])+sin(p[2])
  cos(p[1])+sin(p[2])+cos(p[3])
}
cov.areal<-NULL
#cov.areal<-matrix(c(9,2,3))
#cov.areal<-cbind(c(9,2,3),c(5,2,4))
observations.pointwise<-c()
locations<-matrix(nrow=0,ncol=ncol(nodes))
observations.areal<-rep(0,nrow(incidence_matrix))
ref<-matrix(NA,nrow=0,ncol=2)
for (i in 1:nrow(incidence_matrix)){
  for (j in 1:ncol(incidence_matrix)){
    if (incidence_matrix[i,j]==1){
      for (k in 1:ncol(elems)){
        if (!inside(c(elems[j,k],i),ref)){
          ref<-rbind(ref,c(elems[j,k],i))
        }
      }
      observations.areal[i]<-observations.areal[i]+sum(sapply(1:ncol(elems),function(k){z(nodes[elems[j,k],])}))
    }
  }
}
observations.areal<-observations.areal/(ncol(elems)*apply(incidence_matrix,1,sum))
locations<-nodes[ref[,1],]
observations.pointwise<-apply(locations,1,z)
cov.pointwise<-cov.areal[ref[,2],]

if (dimension=="2"){
  mesh<-create.MESH.2D(nodes=nodes,triangles=elems)
}else if (dimension=="2.5"){
  mesh<-create.MESH.2.5D(nodes=nodes,triangles=elems)
}else if (dimension=="3"){
  mesh<-create.MESH.3D(nodes=nodes,tetrahedrons=elems)
}

FEMbasis<-create.FEM.basis(mesh)

lambda<-10^(-3:3)
GCV<-TRUE
smooth.pointwise<-smooth.FEM.basis(locations=locations,observations=observations.pointwise,
                                   FEMbasis=FEMbasis,lambda=lambda,covariates=cov.pointwise,GCV=GCV)
smooth.areal<-smooth.FEM.basis(observations=observations.areal,FEMbasis=FEMbasis,lambda=lambda,
                               covariates=cov.areal,incidence_matrix=incidence_matrix,GCV=GCV)

smooth.pointwise$GCV
smooth.areal$GCV
if (is.null(cov.areal)){
  RMSE.pointwise<-sqrt(mean((apply(nodes,1,z)-smooth.pointwise$fit.FEM$coeff[,which.min(smooth.pointwise$GCV)])^2))
  RMSE.areal<-sqrt(mean((apply(nodes,1,z)-smooth.areal$fit.FEM$coeff[,which.min(smooth.areal$GCV)])^2))
  mean.absz<-sum(abs(apply(nodes,1,z)))/nrow(nodes)
}else{
  truez<-observations.pointwise
  wbhat<-c(cov.pointwise%*%smooth.pointwise$beta)
  fhat<-smooth.pointwise$fit.FEM$coeff[ref[,1],which.min(smooth.pointwise$GCV)]
  RMSE.pointwise<-sqrt(mean((truez-wbhat-fhat)^2))
  zbar<-observations.areal
  wbarbhat<-c(cov.areal%*%smooth.areal$beta)
  fbarhat<-rep(0,nrow(incidence_matrix))
  for (i in 1:nrow(incidence_matrix)){
    fbarhat[i]<-sum(smooth.areal$fit.FEM$coeff[ref[which(ref[,2]==i),1],which.min(smooth.areal$GCV)])
  }
  fbarhat<-fbarhat/table(ref[,2])
  RMSE.areal<-sqrt(mean((zbar-wbarbhat-fbarhat)^2))
  mean.absz<-sum(abs(apply(locations,1,z)))/nrow(locations)
}
RMSE.pointwise
RMSE.areal
RMSE.pointwise/mean.absz
RMSE.areal/mean.absz

#plot.FEM(smooth.pointwise$fit.FEM)
#plot.FEM(smooth.areal$fit.FEM)
