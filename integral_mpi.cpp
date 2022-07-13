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
    double cnt = 0.0, sum = 0.0, total = 0.0;
    int num = 100000;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myrank);
    srand(time(0));
    int st = num/numprocs * myrank;
    for(int i = st; i < st + num / numprocs; ++i){
        double x = (double) 3*i/num;
        sum += x * x * x;
    }
    if(myrank){
        MPI_Send(&sum, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
    }
    else{
        total = sum;
        for(int np = 1; np < numprocs; ++np){
            MPI_Recv(&sum, 1, MPI_DOUBLE, np, 0, MPI_COMM_WORLD, &status);
            total += sum;
        }
    }
    if(!myrank)
        cout << 3 * total / num << '\t' << myrank << " of " << numprocs << endl; 
    MPI_Finalize();
    finish = clock();
    cout << (double) (finish - start) / CLOCKS_PER_SEC << endl;
    return 0;
}