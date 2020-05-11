#if !defined(__TOMBSTONES_H__)
#define __TOMBSTONES_H__
using namespace std;

void danglingReferenceException()
{
	cout<<"Dangling Reference Exception!!"<<endl;
	exit(1);
}

void memoryLeakException()
{
	cout<<"Memory Leak Exception!!"<<endl;
	exit(1);
}

template <class T> class Pointer;
template <class T> class Tombstone;

template <class T> 
class Tombstone 
{
public:
	int reference;	
	T* value;				
	bool inUse;				
	Tombstone<T>()
	{			
        reference = 0;
        value = NULL;
        inUse = false;
    }
};

template <class T>
class Pointer {	
public:
Tombstone <T> *ptr;
    Pointer<T>()
	{
		
		ptr = new Tombstone<T>();
        ptr->inUse = true;
	}                            
    Pointer<T>(Pointer<T>& y)
	{
		if(y.ptr->inUse) 
		{
			danglingReferenceException();
		}
		ptr = y.ptr;
		if(ptr->reference != 0) ptr->reference++; 
	}
    Pointer<T>(T* x)
	{
        ptr = new Tombstone<T>();
		ptr->value = x;
        ptr->inUse = false;
		if(x != NULL)
		{
			ptr->reference = 1; 
		}
		else
		{
			ptr->reference = 0;
		}
	}
	
    ~Pointer<T>()
	{
		ptr->reference--; 
		if(ptr->reference == 0 && !ptr->inUse)
		{
            memoryLeakException();	
        }
        ptr = NULL;
	}

    T& operator*() const
	{
		if(ptr->reference==0)
		{
            memoryLeakException();
		}
		else if(ptr->inUse == true)
		{
			danglingReferenceException();	
		}else{
            return *(ptr->value); 
        }

	}
    T* operator->() const
	{
        
		if(ptr->reference==0)
		{
            memoryLeakException();
		}
		else if(ptr->inUse == true)
		{
			danglingReferenceException();	
		}else{
            return ptr->value;
        }

	}
    Pointer<T>& operator=(const Pointer<T>& t){ 	
        ptr->reference--;
        if(ptr->reference == 0)
		{
            memoryLeakException();
		}
		ptr = t.ptr;
		ptr->reference++; 
		if(ptr->inUse)
		{
			danglingReferenceException();	
        }
		return *this; 
	}  
	
    friend void free(Pointer<T>& t)
	{
        if(t.ptr->inUse)
		{
			danglingReferenceException();
        }else
		{
            delete t.ptr->value; 
			t.ptr->inUse = true; 
        }
    }
 
    bool operator==(const Pointer<T>& t) const
	{
		if(ptr->inUse|| (t.ptr->inUse))
		{
			danglingReferenceException();
		}
		else
		{
			return ptr->value == (t.ptr->value);		
		}

	}
    bool operator!=(const Pointer<T>& t) const
	{
		if(ptr->inUse|| (t.ptr->inUse))
		{
			danglingReferenceException(); 
		}
		else
		{
			return ptr->value != (t.ptr->value);	
		}
	}

    bool operator==(const int n) const
	{
		return ptr->value == NULL && n == 0;
	}
    bool operator!=(const int n) const
	{		
        return !(ptr->value == NULL && n == 0);		
	}
};

template <class T>
bool operator==(const int n, const Pointer<T>& t) { 
	return t == n;
}

template <class T>
bool operator!=(const int n, const Pointer<T>& t) { 
	return t != n; 
}


#endif
