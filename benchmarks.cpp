#include <iostream>
#include <iomanip>
#include <ctime>


void insertionSort(int size){
   
}

void selectionSort(int size){
   
}

void bubbleSort(int size){

}

void heapSort(int size){

}

void quickSort(int size){

}

template<class T>
void mergeSort(T* array, int start, int mid, int end){

}

template<class T>
double iTime(T* array, int size){
    double start, finish;
    start = clock();
    insertionSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

template<class T>
double sTime(T* array, int size){
    double start, finish;
    start = clock();
    insertionSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

template<class T>
double bTime(T* array, int size){
    double start, finish;
    start = clock();
    bubbleSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

template<class T>
double hTime(T* array, int size){
    double start, finish;
    start = clock();
    heapSort(size);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

template<class T>
double qTime(T* array, int size){
    double start, finish;
    start = clock();
    quickSort(0);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}


double mTime(int* array, int size){
    double start, finish;
    start = clock();
    mergeSort(array,0,0,0);
    finish = clock();
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

void printBenchmarkTable(){
    std::cout << "Data Size"    << std::setw(15) << "Insertion"  << std::setw(15) << "Selection"  << std::setw(15) << "Bubble" << std::setw(15) 
              << "Heap"         << std::setw(15) << "Quick"      << std::setw(15) << "Merge" << std::endl;
}


// global array pointers
int* iArray, *sArray, *bArray, *hArray, *qArray, *mArray;

int main() {
    int arraySize[] = {100000, 200000, 300000, 400000, 500000};
    int len = sizeof(arraySize)/sizeof(arraySize[0]);
    srand(time(0));

    printBenchmarkTable();
    for(int i=0; i<len; i++){          
        // dynamically allocate new memory
        int size = arraySize[i];
        iArray = new int[size];
        sArray = new int[size];
        bArray = new int[size];
        hArray = new int[size];
        qArray = new int[size];
        mArray = new int[size];

        // randomize each array
        for(int j=0; j<arraySize[i]; j++){  
            int randomVal = rand() % 100;
            iArray[j] = randomVal;
            sArray[j] = randomVal;
            bArray[j] = randomVal;
            hArray[j] = randomVal;
            qArray[j] = randomVal;
            mArray[j] = randomVal;
        }
        
        // benchmarking
        std::cout<< size
                 << std::setw(15) << iTime(iArray, size) << std::setw(15) << sTime(sArray, size) << std::setw(15) << bTime(bArray, size) << std::setw(15) << hTime(hArray, size)
                 << std::setw(15) << qTime(qArray, size) << std::setw(15) << mTime(mArray, size) << std::endl;

        // free memory
        delete iArray;  iArray = nullptr;
        delete sArray;  sArray = nullptr;
        delete bArray;  bArray = nullptr;
        delete hArray;  hArray = nullptr;
        delete qArray;  qArray = nullptr;
        delete mArray;  mArray = nullptr;
    
    }    
}