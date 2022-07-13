#include <iostream>
#include <mpi.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

double uniformRand(){
	return (double) rand() / RAND_MAX;
}

int main(int argc, char *argv[]){
    int numprocs, myrank;
    MPI_Status status;
    double cnt = 0.0, sum = 0.0;
    int num = 1000000000;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    srand(time(0));
    for(int i = 0; i < num; ++i){
        // srand(time(0));
        double x = uniformRand();
        sum += sqrt(1 - x*x);
    }

    cout << time(0) << endl << 4 * sum / num << '\t' << myrank << " of " << numprocs << endl; 
    MPI_Finalize();
    return 0;
}