from mpi4py import MPI
COMM=MPI.COMM_WORLD
RANK=COMM.Get_rank()
SIZE=COMM.Get_size()
print("Hello from the rank {RANK} process".format(RANK=RANK))
COMM.barrier() #Bloque jusqu'à ce que tous les processus du communicateur aient atteint cette routine.
if RANK==3:
  print("Parallel execution of hello_world with {SIZE} process".format(SIZE=SIZE))