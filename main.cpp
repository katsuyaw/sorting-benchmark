#include <iostream>
#include <iomanip>
#include <ctime>


template<class T>
void insertionSort(T* arr, int size)
{   
    int target, location;
    T key;

    for(target=0; target<size; target++){
        // condition: next element of target is smaller than target
        if(arr[target]>arr[target+1]){
            // record the location of the next element
            location = target + 1;
            // store the element to key
            key = arr[location];

            // keep moving each element to the right by 1
            do{
                arr[location] = arr[location-1];
                location--;
            }// until the element moving is smaller than key
            while(location>0 && arr[location-1]>key);
            // locate key to the position
            arr[location] = key;
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
void selectionSort(T* arr, int size){
    // target is the value to be campared with
    // minIndex is to be updated with the location of new smaller value
    int target, minIndex, location;

    for(target=0; target<size-1; target++){

        minIndex = target;  // initialize minIndex with target

        for(location=target+1; location<size-1; location++){
            // condition: if element smaller than current minIndex found
            if(arr[minIndex]>arr[location]){
                // update minIndex
                minIndex = location;
            }
        }
        swap(arr[target], arr[minIndex]);
    }
}

template<class T>
void bubbleSort(T* arr, int size){
    int i, j;
    bool swapped;

    for (i = 0; i < size-1; i++){
        swapped = false;

        for (j = 0; j < size-i-1; j++){
        
            if (arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
     }
  
     // condition: No swap then done
    if (swapped == false)
        break;
   }
}

template<class T>
void heapify(T* arr, int size, int i){
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
    // leftchild > root
	if (l < size && arr[l] > arr[largest])
	largest = l;
    // rightchild > root
	if (r < size && arr[r] > arr[largest])
	    largest = r;
    // if largest is not root
	if (largest != i){
		swap(arr[i], arr[largest]);
        // recursively heapify the affected sub-tree
		heapify(arr, size, largest);
	}
}

template<class T>
void heapSort(T* arr, int size){
    // build heap
	for (int i = size; i >= 0; i--)
	    heapify(arr, size, i);
	for (int i = size; i > 0; i--){
        // move current root to end
		swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
		heapify(arr, i, 0);
	}
}

template<class T>
int partition (T* arr, int start, int end){
    // set pivot at the end
    int pivot = arr[end];
    int i = (start - 1);
 
    for (int j = start; j <= end - 1; j++){
        // element < pivot
        if (arr[j] < pivot){
            // increment i(smaller) and swap with j
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // place pivot
    swap(arr[i + 1], arr[end]);
    return (i + 1);
}

template<class T>
void quickSort(T* arr, int start, int end){   
    if (start < end){
        // index of pivot
        int index = partition(arr, start, end);
        // quicksort upperhalf
        quickSort(arr, start, index-1);
        // quicksort lowerhalf
        quickSort(arr, index+1, end);
    }
}

template<class T>
void merge(T* arr, int start, int mid, int end) {
    int size = end - start + 1;
	int temp[size];
	int i = start, 
    j = mid+1, 
    k = 0;

    // store smaller value to temp
	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k++; i++;
		}
		else {
			temp[k] = arr[j];
			k++; j++;
		}
	}

	// store remaining elements 
	while(i <= mid) {
		temp[k] = arr[i];
		k++; i++;
	}
	while(j <= end) {
		temp[k] = arr[j];
		k++; j++;
	}
    // store to array
	for(i = start; i <= end; i++) 
		arr[i] = temp[i - start];
}

template<class T>
void mergeSort(T* arr, int start, int end){
	if (start < end){
        // find middle
		int middle = start + (end - start) / 2;
        // merge sort lower half
		mergeSort(arr, start, middle);
        // merge sort upper half
		mergeSort(arr, middle + 1, end);
        // merge
		merge(arr, start, middle, end);
	}
}

template<class T>
double sortTime(T* arr, int size, char sortType){
    clock_t start, finish;

    // i for insertion, s for selection, b for bubble, h for heap, q for quick, m for merge
    // returns sort time accordingly
    switch(sortType){
        case 'i':{
            start = clock();
            insertionSort(arr, size);
            finish = clock();
            break;
        }
        case 's':{
            start = clock();
            selectionSort(arr, size);
            finish = clock();
            break;
        }
        case 'b':{
            start = clock();
            bubbleSort(arr, size);
            finish = clock();
            break;
        }
        case 'h':{
            start = clock();
            heapSort(arr, size);
            finish = clock();
            break;
        }
        case 'q':{
            start = clock();
            quickSort(arr, 0, size-1);
            finish = clock();
            break;
        }
        case 'm':{
            start = clock();
            mergeSort(arr, 0, size-1);
            finish = clock();
            break;
        }

    }
    return (double)((finish - start) / (double)CLOCKS_PER_SEC);
}

// print benchmark table
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
        
        // print sort time for each sort method
        std::cout<< size
                 << std::setw(20) << sortTime(iArray, size, 'i') << std::setw(15) << sortTime(sArray, size, 's') << std::setw(15) << sortTime(bArray, size, 'b') 
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