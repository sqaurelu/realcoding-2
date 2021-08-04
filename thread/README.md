# thread(2020-08-12)

## score_using_thread.c 설명
- sthread1 : 전체 성적의 평균, 합을 내는 쓰레드
- sthread2 : 성적순으로 sorting을 해서 출력하는 쓰레드

## thread: 어떤 프로그램에서 프로그램이 실행되는 흐름의 단위
1. `create_thread()` - 쓰레드를 생성하는 함수
- 함수의 프로토타입
```
int pthread_create(pthread_t *thread, const pthread_attr_t *attr,  
                void *(*start_routine)(void *), void *arg);
```
- thread : 쓰레드의 식별자 정보를 담고 있다.
- attr : 쓰레드 속성을 넣는 곳이며 기본 쓰레드 속성을 이용하고자 할 경우에 NULL을 사용한다.
- start_routine : 분기시켜서 실행할 쓰레드 함수
- arg : 쓰레드 함수의 인자

2. `pthread_exit()`
- 커널이 메인 메모리를 접근하는 쓰레드가 있으면 메모리를 해제하지 않도록 하는 함수(쓰레드는 메모리를 공유하는데, 공유되는 메모리는 메인함수로부터 시작된다. 따라서 메인함수가 종료되면 커널이 공유 메모리를 없애버리기 때문에 자식 쓰레드들도 강제로 종료된다.)
