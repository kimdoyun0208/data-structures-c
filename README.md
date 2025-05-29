C언어 자료구조 구현
==========

이 리포지토리는 C 언어를 사용하여 기본 자료구조를 구조체 기반으로 구현한 예제입니다. 각 자료구조는 독립적인 디렉토리로 구성되어 있으며, 각각의 디렉토리에는 해당 자료구조의 헤더 파일, 구현 파일, 테스트용 `main.c` 파일, 그리고 빌드를 위한 `Makefile`이 포함되어 있습니다.

## 구현된 자료구조
1. **스택 (Stack)**
   - [**연결 리스트 기반 (stack-linkedlist)**](stack-linkedlist/)
   - [**배열 기반 (stack-array)**](stack-array/)
2. **큐 (Queue)**
   - [**연결 리스트 기반 (queue-linkedlist)**](queue-linkedlist/)
   - [**배열 기반 (queue-array)**](queue-array/)
3. [**연결 리스트 (linked-list)**](linked-list/)
4. [**이중 연결 리스트 (doubly-linked-list)**](doubly-linked-list/)

## 디렉토리 구조
```
data-structures-c/
├── stack-linkedlist/
├── stack-array/
├── queue-linkedlist/
├── queue-array/
├── linked-list/
└── doubly-linked-list/
```

## 빌드 및 실행 방법
각 자료구조 디렉토리에는 `Makefile`이 포함되어 있어 간단한 명령어로 빌드 및 실행이 가능합니다. _(Windows에서는 작동하지 않습니다)_

### 빌드
```bash
make
```

### 실행
```bash
make run
```

### 클린업
```bash
make clean
```