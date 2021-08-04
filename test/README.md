# SW TESTING(2020-08-18/19/20/21)


|   | Black-Box Testing | White-Box Testing|
|-------- |--------|--------|
| Static Testing         | Documentation Review <br>- Requirement Review<br>- Specification Inspection    | Source code Review<br>- Cyclomatic complexity<br>- Static Analysis|
| Dynamic Testing        | Specification-based Testing<br>- Integration Testing<br>- System Testing   | Structural Testing<br>- Statement coverage Testing<br>- Branch coverage Testing  |


### 정적 테스트
- 소프트웨어를 실행하지 않고 결함을 검출하는 방법
- 코딩 규칙이 제대로 되었는지를 보는 것. 코딩의 기능적인 부분을 구현하는 것은 아니다.
- 테스트의 종료 기준을 명확하게 정하는게 필요하다.
- 어떤 테스트를 수행할 것인가를 설정해야 한다.

#### (2020-08-19 과제)
- Code Inspector 프로그램을 이용해서 MISRA_C_2012 규칙에 맞춰 test.c 파일을 테스트 해봄.

<img src="./images/capture_1.JPG" alt="1" width="80%">
<p>위배 사항 고치기 전 : 94개</p>

<img src="./images/capture_2.JPG" alt="2" width="80%">
<p>위배 사항 고치기 후 : 32개</p>


### 동적 테스트
- 개발된 프로그램을 실행하여 테스트를 하는 방법
- 실행하여 실제 발생하는 오류, 문제를 해결한다.

#### (2020-08-20 과제)
- test.c 파일의 ArrayTest와 StaticVarTest에 대해 구문, 분기 커버리지 100% 완성
- ArrayTest

<img src="./images/unittest2.JPG" alt="2" width="40%"><img src="./images/unittest3.JPG" alt="3" width="40%"><img src="./images/unittest4.JPG" alt="4" width="40%">
<img src="./images/unittest7.JPG" alt="7">

- StaticVarTest

<img src="./images/unittest6.JPG" alt="6" width="40%">
<img src="./images/unittest8.JPG" alt="8">

