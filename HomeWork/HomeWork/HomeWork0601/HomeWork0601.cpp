// HomeWork0601.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <list>
#include <vector>
#include <assert.h>
#include <crtdbg.h>


using DataType = int; //DataType은 int라고 사용할 것이다. 

class HList //class도 자료형의 일종이다. 잊지 말자! 
{

	 
private:
	 
	class ListNode //ListNode는 HList의 중첩 클래스. 별개의 클래스이므로 서로 영향을 끼칠 수 없다. 
	{
	public: //ListNode의 멤버변수 
		DataType Value; //DataType Value; => int Value; 
		ListNode* Prev = nullptr; //값이 존재하지 않을 수도 있을 때. 정수로 치면 0. nullPtr로 반드시 체크하고 넘어가야 한다.  
		ListNode* Next = nullptr; //Prev 와 Next는 변수 이름. 
	};


public:
	
	class iterator //iterator는 HList의 중첩 클래스. 별개의 클래스이므로 서로 영향을 끼칠 수 없다. 
	{
		friend HList; //HList의 private에 접근 가능하다는 의미. 
		
	private:
		ListNode* CurNode = nullptr; //값이 존재하지 않을 수도 있을 때. 정수로 치면 0. nullPtr로 반드시 체크하고 넘어가야 한다.  

	public:
		iterator() //클래스 iterator의 생성자 
		{

		}

		iterator(ListNode* _Node) //멤버이니셜라이저
			: CurNode(_Node)
		{

		}
		//&은 200번지에 있는 100번지다, &는 주소값을 끄집어 내는 것. 
		//연산자 오퍼레이터를 이용한 bool 데이터. !=는 같지 않다는 의미.
		//연산자 오버로딩은 특정 타입의 객체가 피연산자로 들어올 시 어떤 행동을 하게끔 미리 정의하는 것. 
		bool operator !=(const iterator& _Other) //iterator형 _Other라는 매개변수라고 레퍼런스 선언 
		{
			return CurNode != _Other.CurNode; //iterator형 _Other의 CurNode이 아니라는 값을 반환. 
		}

		iterator& operator ++() //iterator 자료형을 &한 연산자 오퍼레이트 ++를 사용? 
		{
			CurNode = CurNode->Next; //디버그시 에러 발견
			return *this; //CurNode의 주소값
		}

		DataType& operator*() //int형 자료형을 &한 연산자 오퍼레이트*
		{
			return CurNode->Value;
		}
	};

	HList()
	{
		StartNode = new ListNode(); //new로 할당. 여기서 추후에 delete를 해야함. 
		EndNode = new ListNode();

		// 이게 더미 노드 방식
		StartNode->Next = EndNode; //맨 처음의 다음은 맨 끝 
		EndNode->Prev = StartNode; //맨 끝의 앞은 맨 처음 
	}

	//void Push_front를 만들어보세요.
	//클래스 iterator의 멤버함수. push_back은 리스트 제일 뒤에 원소를 추가하는 것. 
	void push_back(const DataType& _Data) 
	{
		ListNode* NewNode = new ListNode(); 
		//ListNode, 변수 그 자체가 되는 문법이 *이었다. ListNode는 클래스 이름이므로 자료형, NewNode은 변수 이름임. 즉, ListNode형 NewNode는 new ListNode()이라고 대입됨.
		NewNode->Value = _Data; //NewNode 변수의 Value는 _Data라는 매개변수 

		ListNode* PrevNode = EndNode->Prev; //PrevNode 변수에 EndNode의 Prev를 대입. 

		//양방향 노드. 서로 앞뒤가 연결되어 있다. 
		PrevNode->Next = NewNode;
		EndNode->Prev = NewNode;

		NewNode->Next = EndNode;
		NewNode->Prev = PrevNode;
	}

	//클래스 iterator의 멤버함수. push_front은 리스트 제일 앞에 원소를 추가하는 것. 
	void push_front(const DataType& _Data)  
	{
		ListNode* NewNode = new ListNode();

		NewNode->Value = _Data;

		ListNode* FirstNode = StartNode->Prev;
		StartNode->Prev = NewNode; 
		EndNode->Next = NewNode;

		NewNode->Next = StartNode;
		NewNode->Prev = EndNode;
				
	}

	iterator erase(const iterator& _Iter) //iterator형 _Iter 매개변수, iterator형의 erase 함수
	{
		ListNode* Node = _Iter.CurNode; //ListNode형 Node 변수는 _Iter의 CurNode.

		// 터져야 한다.
		if (StartNode == Node
			|| EndNode == Node) //StartNode나 EndNode가 _Iter의 CurNode라면 
		{
			assert(false);
			return iterator(EndNode); //iterator의 EndNode, _Iter의 CurNode로 반환? 
		}

		// 삭제할때 언제나 내가 정리하거나 잃어버려서 곤란한 데이터들이
		// 존재하는지를 언제나 확인하셔야 합니다.
		// 정리할게 있나 없나를 확인해야 한다.

		//그후에 양방향 노드 
		ListNode* NextNode = Node->Next;
		ListNode* PrevNode = Node->Prev;

		PrevNode->Next = NextNode;
		NextNode->Prev = PrevNode;

		//그 다음에 if문 
		if (nullptr == Node) // Node변수가 null이면 
		{
			delete Node; //Node를 delete한다. 
		}
		//if문 다음에 iterator의 NextNode로 반환. 
		return iterator(NextNode);
	}

	//처음부터 다음으로? 
	iterator begin()
	{
		return iterator(StartNode->Next);
	}

	//마지막, 끝
	iterator end()
	{
		return iterator(EndNode);
	}

private:
	 //외부에서 건드리면 안 되는 
	ListNode* StartNode;
	ListNode* EndNode;
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	{
		std::vector<int> Test;

		// 노드형 시퀀스 자료구조
		std::list<int> NewList;

		

		for (size_t i = 0; i < 10; i++)
		{
			// 리스트만 가지고 있는 함수인데.
			NewList.push_front(i); //NewList의 push_front(i) 함수를 사용하겠다. 
		}

		// NewList.erase()

		std::list<int>::iterator StartIter = NewList.begin();
		std::list<int>::iterator EndIter = NewList.end();

		StartIter = NewList.erase(StartIter);

		for (; StartIter.operator!=(EndIter); ++StartIter)
		{
			std::cout << (*StartIter) << std::endl;
		}
	}

	{
		
		// 노드형 시퀀스 자료구조
		HList NewList;

		HList::iterator StartIter = NewList.begin();
		HList::iterator EndIter = NewList.end();

		HList::iterator EraseIter = NewList.begin();

		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;
		++EraseIter;

		EraseIter = NewList.erase(EraseIter);


		for (; StartIter != EndIter; ++StartIter)
		{
			// 순회를 하면서 모든 인자를 도는 와중에 삭제를 합니다.
			std::cout << (*StartIter) << std::endl;
		}
	}

}
