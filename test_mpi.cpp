#include <iostream>
#include <mpi.h>
#include <cmath>

using namespace std;

int main(int argc, char *argv[]){
    int numprocs, myrank;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    cout << "Hello world from process " << myrank << " of " << numprocs << endl; 
    MPI_Finalize();
    return 0;
}