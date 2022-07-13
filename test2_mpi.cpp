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
    clock_t start, finish;
    start = clock();
    int numprocs, myrank;
    MPI_Status status;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    srand(time(0));
    int sum_mpi = 0;
    for(int i = 0; i < 1000; ++i){
        if(i % 100 == 0){
            MPI_Reduce(&i, &sum_mpi, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
            //if(myrank == 0){
                cout << sum_mpi << endl;
            //}
        }
        
    }
    MPI_Finalize();
    finish = clock();
    cout << (double) (finish - start) / CLOCKS_PER_SEC << endl;
    return 0;
}