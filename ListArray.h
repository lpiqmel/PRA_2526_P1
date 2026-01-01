#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;

	void resize(int new_size){
		if (new_size <=0){
			throw std::invalid_argument("Tamaño invalido");
		}

		T* new_arr =new T[new_size];
		for (int i = 0; i < n && i < new_size; ++i) {
            		new_arr[i] = arr[i];
        	}

		delete[] arr;
		arr = new_arr;
		max = new_size;
	}


    public:
	ListArray(){
		arr = new T[MINSIZE];
		max = MINSIZE;
		n = 0;
	}

	~ListArray(){
		delete[] arr;
	}
    
	T operator[](int pos) {
        	if (pos < 0 || pos >= max-1) {
            		throw std::out_of_range("Índice fuera de rango");
        	}
        	return arr[pos];
	}

	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		for (int i = 0; i < list.max; ++i) {
            		out << list.arr[i] << " ";
		}
		return out;
	}
};
