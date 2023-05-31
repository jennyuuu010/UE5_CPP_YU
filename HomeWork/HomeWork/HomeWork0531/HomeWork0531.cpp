#include <iostream>
#include <vector>
#include <crtdbg.h> 

// stl은 템플릿만 사용했다면 다 stl
// 자료구조템플릿 != stl 
// stl중 자료구조 stl이라고 합니다.
// C++을 만든

// stl에 포함된 자료구조형 템플릿 클래스들을 배우는 겁니다.

// std 자료구조가 할수 있다면
// 나도 똑같은 짓을 하고 똑같은 결과를 내는 클래스를 만들어 보는게.

// 숙제 => HVector의 leck을 없애와라
//         대입연산자를 사용하면 터지는걸 정상으로 돌려놔라.
//         이미 보여준 코드 이미 array에서 해결은 한거에요.


template<typename DataType>

class HVector
{
public:
	HVector()
	{

	}
		

	HVector(const HVector& _Other)
	{
		//100번지     100번지
		// ArrValue = _Other.ArrValue;

		if (0 >= _Other.SizeValue)
		{
			return;
		}

		Resize(_Other.SizeValue);
		Copy(_Other);
	}


	DataType& operator[](size_t _Index)
	{
		return ArrPtr[_Index];
	}

	size_t Size() const
	{
		return sizeValue;
	}

	size_t capacity()
	{
		return capacityValue;
	}

	HVector(size_t _Size)
	{
		capacity(_Size);
	}

	void push_back(const DataType& _Data)
	{
		// 확장해야 할때가 있습니다.
		if (sizeValue + 1 > capacityValue)
		{
			reserve((int)((capacityValue * 1.5) + 1));
		}

		ArrPtr[sizeValue] = _Data;
		sizeValue += 1;
	}

	void reserve(size_t _capacity)
	{
		DataType* PrevPtr = ArrPtr;

		// 1회의 new가 일어났다면 1회의 delete가 어딘가에 존재해야 한다.
		ArrPtr = new DataType[_capacity];

		// 최초에 한번은 내가 nullptr 이었을것이다.
		if (nullptr != PrevPtr)
		{
			for (size_t i = 0; i < sizeValue; i++)
			{
				ArrPtr[i] = PrevPtr[i];
			}
			Clear();


		}

		capacityValue = _capacity;
		
	}
	

	void Copy(const HVector& _Other)
	{
		size_t VSize = Size() <= _Other.Size() ? Size() : _Other.Size();

		for (size_t i = 0; i < VSize; i++)
		{
			ArrPtr[i] = _Other[i];

		}
	
	}

	void Clear()
	{
		if (nullptr != ArrPtr)
		{
			delete ArrPtr;
			ArrPtr = nullptr;
		}
	}

	~HVector()
	{
		Clear();
	}

private:
	int sizeValue = 0;
	int capacityValue = 0;
	DataType* ArrPtr = nullptr;
};

int main()
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

		
		HVector<int> Arr;
		// 내부에 123
		// Arr.reserve(10);
		for (size_t i = 0; i < 10; i++)
		{
			Arr.push_back(i);
			//std::cout << "size : " << Arr.size() << std::endl; // 원소의수
			//std::cout << "capacity : " << Arr.capacity() << std::endl; // 메모리의 크기
		}

		for (size_t i = 0; i < Arr.Size(); i++)
		{
			std::cout << Arr[i] << std::endl;
		}


		HVector<int> Arr0;

		// 릭을 해결하는 순간 터질겁니다.
		// 정상적인 복사가 이루어지게 하세요.
		Arr0 = Arr;

		for (size_t i = 0; i < Arr0.Size(); i++)
		{
			std::cout << Arr0[i] << std::endl;
		}

	



}
