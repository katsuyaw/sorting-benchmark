#include <iostream>
#include <iomanip>
#include <ctime>


template<class T>
void insertionSort(T* array, int size)
{   
    int target, location;
    T key;

    for(target=0; target<size; target++){
        // condition: next element of target is smaller than target
        if(array[target]>array[target+1]){
            // record the location of the next element
            location = target + 1;
            // store the element to key
            key = array[location];

            // keep moving each element to the right by 1
            do{
                array[location] = array[location-1];
                location--;
            }// until the element moving is smaller than key
            while(location>0 && array[location-1]>key);
            // locate key to the position
            array[location] = key;
        }
    }
}

template<class T>
void swap(T& a, T& b){  
    T temp = a;
    a = b;
    b = temp;
}

template<class T>
void selectionSort(T* array, int size){
    // target is the value to be campared with
    // minIndex is to be updated with the location of new smaller value
    int target, minIndex, location;

    for(target=0; target<size-1; target++){

        minIndex = target;  // initialize minIndex with target

        for(location=target+1; location<size-1; location++){
            // condition: if element smaller than current minIndex found
            if(array[minIndex]>array[location]){
                // update minIndex
                minIndex = location;
            }
        }
        swap(array[target], array[minIndex]);
    }
}

template<class T>
void bubbleSort(T* array, int size){
    int i, j;
    bool swapped;

    for (i = 0; i < size-1; i++){
        swapped = false;

        for (j = 0; j < size-i-1; j++){
        
            if (array[j] > array[j+1]){
                swap(array[j], array[j+1]);
                swapped = true;
            }
     }
  
     // condition: No swap then done
    if (swapped == false)
        break;
   }
}

template<class T>
void heapify(T* array, int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && array[l] > array[largest])
	largest = l;
	if (r < n && array[r] > array[largest])
	largest = r;
	if (largest != i){
		int temp = array[i];
		array[i] = array[largest];
		array[largest] = temp;
		heapify(array, n, largest);
	}
}

template<class T>
void heapSort(T* array, int n)
{
	int i = 0;
	for (i = n; i >= 0; i--)
	heapify(array, n, i);
	for (i = n; i > 0; i--){
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		heapify(array, i, 0);
	}
}

template<class T>
int partition (T* array, int low, int high)
{
    int pivot = array[high]; // pivot
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
 
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(array[i], array[j]);
        }
    }
    swap(array[i + 1], array[high]);
    return (i + 1);
}
 

template<class T>
void quickSort(T* array, int low, int high)
{
    // if (low < high)
    // {
    //     /* pi is partitioning index, arr[p] is now
    //     at right place */
    //     int pi = partition(&array, low, high);
 
    //     // Separately sort elements before
    //     // partition and after partition
    //     quickSort(&array, low, pi - 1);
    //     quickSort(&array, pi + 1, high);
    // }
}

template<class T>
void merge(T* array, int start, int mid, int end) {
    int size = end - start + 1;
	int temp[size];
	int i = start, 
    j = mid+1, 
    k = 0;

    // store smaller value to temp
	while(i <= mid && j <= end) {
		if(array[i] <= array[j]) {
			temp[k] = array[i];
			k++; i++;
		}
		else {
			temp[k] = array[j];
			k++; j++;
		}
	}

	// store remaining elements 
	while(i <= mid) {
		temp[k] = array[i];
		k++; i++;
	}

	while(j <= end) {
		temp[k] = array[j];
		k++; j++;
	}

	for(i = start; i <= end; i++) 
		array[i] = temp[i - start];
}

template<class T>
void mergeSort(T* array, int start, int end){
	if (start < end){
		int middle = start + (end - start) / 2;
		mergeSort(array, start, middle);
		mergeSort(array, middle + 1, end);
		merge(array, start, middle, end);
	}
}

template<class T>
double sortTime(T* array, int size, char sortType){
    clock_t start, finish;
    switch(sortType){
        case 'i':{
            start = clock();
            insertionSort(array, size);
            finish = clock();
            break;
        }
        case 's':{
            start = clock();
            selectionSort(array, size);
            finish = clock();
            break;
        }
        case 'b':{
            start = clock();
            bubbleSort(array, size);
            finish = clock();
            break;
        }
        case 'h':{
            start = clock();
            heapSort(array, size);
            finish = clock();
            break;
        }
        case 'q':{
            start = clock();
            quickSort(array, 0, size-1);
            finish = clock();
            break;
        }
        case 'm':{
            start = clock();
            mergeSort(array, 0, size);
            finish = clock();
            break;
        }

    }
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}


void printBenchmarkTable(){
    std::cout << "Data Size"    << std::setw(15) << "Insertion"  << std::setw(15) << "Selection"  << std::setw(15) << "Bubble" << std::setw(15) 
              << "Heap"         << std::setw(15) << "Quick"      << std::setw(15) << "Merge" << std::endl;
}


// global array pointers
int* iArray, *sArray, *bArray, *hArray, *qArray, *mArray;

int main() {
    int arraySize[] = {10000, 20000, 30000, 40000, 50000};
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
        
        std::cout<< size
                 << std::setw(15) << sortTime(iArray, size, 'i') << std::setw(15) << sortTime(sArray, size, 's') << std::setw(15) << sortTime(bArray, size, 'b') 
                 << std::setw(15) << sortTime(hArray, size, 'h') << std::setw(15) << sortTime(qArray, size, 'q') << std::setw(15) << sortTime(mArray, size, 'm') << std::endl;


        // free memory
        delete iArray;  iArray = nullptr;
        delete sArray;  sArray = nullptr;
        delete bArray;  bArray = nullptr;
        delete hArray;  hArray = nullptr;
        delete qArray;  qArray = nullptr;
        delete mArray;  mArray = nullptr;
    
    }    
}