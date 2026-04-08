class DynamicArray {
public:

    int size, capacity;
    int* arr;

    DynamicArray(int capacity) : capacity(capacity), size(0) {
        arr = new int[capacity];
    }

    ~DynamicArray() {
        delete[] arr;
        arr = nullptr;
    }

    int get(int i) {
        return *(arr + i);
    }

    void set(int i, int n) {
        *(arr + i) = n;
    }

    void pushback(int n) {
        if(size == capacity)
            resize();
        
        *(arr + size) = n; 
        size++;
    }

    int popback() {
        int index = size - 1;
        size--;
        return *(arr + index);
    }

    void resize() {
        capacity *= 2;
        int* temp = new int[capacity];

        for(int i = 0; i < size; i++){
            *(temp + i) = *(arr + i);
        }

        delete[] arr;
        arr = temp;
        temp = nullptr;

    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
