from mpi4py import MPI

COMM=MPI.COMM_WORLD
RANK=COMM.Get_rank()
if RANK==0:
    data=int(input("processus {RANK}, tapez un numero : ".format(RANK=RANK))) 
else:
    data=None   
data=COMM.bcast(data,root=0)    
print("processus {RANK} , valeur = {data}".format(RANK=RANK,data=data))    
  

