# POINTER(2020-08-11)

## Three basic memory model in C
automatic, static, manual
1. auto
- 해당 블럭 안에서만 유효하며 블럭의 실행이 끝나면 없어진다.
- 스택에 메모리가 할당된다.
- c언어에서 auto 키워드는 일반적으로 생략되어 있다.
2.  static
- 해당 블럭 안에서만 유효하지만 블럭으로 다시 돌아왔을 때 이전에 있던 값을 다시 사용할 수 있다.
- 프로그램이 실행되고 있는 동안 계속 유지된다.
3. manual
- malloc과 free가 있다.
- 선언한 이후에도 메모리의 사이즈를 줄이거나 늘릴 수 있는 유일한 타입이다.

||  <center>static</center> |  <center>auto</center> |<center>manual</center> |
|:--------|:--------:|--------:|--------:|
|Set to zero on startup | <center> O </center> | <center> X </center> |<center> X </center> |
|Scope-limited | <center> O </center> |<center> O </center> |<center> X </center> |
|Can set values on init | <center> O </center> |<center> O </center> |<center> X </center> |
|Can set nonconstant values on init | <center> X </center> |<center> O </center> |<center> X </center> |
|sizeof measures array size | <center> O </center> |<center> O </center> |<center> X </center> |
|Persists across function calls | <center> O </center> |<center> X </center> |<center> O </center> |
|Can be global | <center> O </center> |<center> X </center> |<center> O </center> |
|Array size can be set at runtime | <center> X </center> |<center> O </center> |<center> O </center> |
|Can be resized | <center> X </center> |<center> X </center> |<center> O </center> |

## Poiner의 기본 개념
1. 포인터 : 메모리의 주소값을 저장하기 위한 변수 
2. 포인터 선언 방법 : 
```
type * ptr;
int * ptr; // int형 포인터
double * ptr; // double형 포인터
long long * ptr; // long long형 포인터
```

3. 포인터 연산자 : 
- & : 변수의 주소값을 반환
- <p>*  : 포인터가 가리키는 메모리를 참조</p>
```
int n = 100;
int * ptr = &n; // 포인터 ptr은 int형 변수 n의 주소값을 가리킨다.
printf("%d\n", *ptr); // 포인터 ptr이 가리키고 있는 변수의 값을 보여준다.
```
4. 배열의 이름도 포인터이다.
- 배열의 이름은 배열의 시작 주소를 가리킨다.
```
int arr[3] = {1, 2, 3};
printf("%d %d\n", arr, arr+1); // arr[0]의 주소, arr[1]의 주소
printf("%d %d\n", *arr, *(arr+1)); // 1, 2
```


## Noun-Adjective Form
- const : 상수화(값이 바뀌지 않길 원할 때) => <strong>수정해도 되는 데이터와 안되는 데이터를 구분할 수 있다. </strong>

<strong>int const a;</strong> - integer 상수
<strong>int const *a;</strong> - 상수 integer를 가리키는 포인터
```
int const pi = 314;
int const *p = &pi; // int const를 가리키는 pointer
```
<strong>int * const a;</strong> - integer를 가리키는 상수 포인터
```
int const pi = 314;
int *a = &pi; // 가리키는 메모리 주소가 안변했으면 좋겠다 => int * const a = &pi;
```
<strong>int * const *a;</strong> - integer 상수 포인터를 가리키는 포인터 <br>
<strong>int const * * a;</strong> - pointer to a pointer to a constant integer<br>
<strong>int const * const * a;</strong> - pointer to a constant pointer to a constant integer<br>



## Pointer – void * 
- 모든 데이터 자료형을 가리킬 수 있는 포인터다.
- ++연산을 하면 1이 증가된다.
- 데이터의 자료형이 정해져 있지 않으므로 역참조가 불가능하다.
```
void *ptr;
int a = 10;

ptr = &a;
printf("%d\n", *ptr); // 에러가 발생
printf("%d\n", *(int *)ptr);    // a: void 포인터를 int형 포인터로 캐스팅한 뒤 역참조 가능

```

## Function pointer

- 함수 포인터 선언하는 방식 : ```반환값자료형 (*함수포인터이름) (인자의 타입);```
```
int sum(int a, int b) {
	return a + b;
}
int main() {
    int (*fp) (int, int); // 함수 포인터 선언
    
    fp = &sum;
    fp = sum; // 함수 포인터에 함수 주소를 할당할 때 &연산자를 안써도 됨.
}
```
	


