import random
import timeit
import numpy as np
from scipy.sparse import lil_matrix
from numpy.random import rand, seed
from numba import njit
from mpi4py import MPI

 

COMM = MPI.COMM_WORLD
nbOfproc = COMM.Get_size()
RANK = COMM.Get_rank()
INTERVAL= 1000
random.seed(42) 

def compute_points():

    random.seed(42) 

    circle_points= 0

    for i in range(INTERVAL**2):

        # Randomly generated x and y values from a uniform distribution

        # Range of x and y values is -1 to 1    

        rand_x= random.uniform(-1, 1)

        rand_y= random.uniform(-1, 1)

        # Distance between (x, y) from the origin

        origin_dist= rand_x**2 + rand_y**2

     

        # Checking if (x, y) lies inside the circle

        if origin_dist<= 1:

            circle_points+= 1

 

    

    return circle_points

 

start = timeit.default_timer()

circle_points = compute_points()

end = timeit.default_timer()

 

if RANK==0:

    pi = 4* circle_points/ INTERVAL**2

    print('Processus 0 \n')
    print("##################################"
    print("circle points number :",circle_points)
    print("##################################")
    print("l'estimation finle de Pi=", pi, "cpu time :",end-start)