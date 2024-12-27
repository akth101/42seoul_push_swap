## push_swap
push_swap 프로젝트는 두 개의 스택 a, b와 제한된 명령어가 주어집니다.  
stack a에 있는 요소들을 오름차순으로 최소한의 instruction을 사용하여 정렬하는 것이 핵심 목표입니다.  
이 프로젝트에서는 그리디 알고리즘을 사용하며, 특히 스택 a에서 b로 요소를 옮길 때 피벗을 설정하여 정렬을 구현합니다.  

목차  
1. 어려웠던 점  
2. 평가 피드백  
3. 프로젝트 개요

### 1. 어려웠던 점  
  **자료구조의 단점만 조합해서 사용함**  
    - 링크드 리스트는 요소의 삽입, 삭제가 쉬운 대신 특정 요소를 찾는 코스트가 많이 들어갑니다.  
    - 배열은 인덱스를 통해 특정 요소에 접근이 쉬운 대신 요소의 삽입과 삭제에 있어 많은 코스트가 들어갑니다.  
    - stack의 실체적 구현으로 배열을 사용했기 때문에 요소의 삽입과 삭제가 비효율적이라는 특성은 가져갈 수밖에 없었습니다.  
    - 그런데 stack의 빈 공간을 INT_MAX값으로 표현하는 개념을 도입함으로써 배열이 얼마나 비어있는지 확인하기 위해  
      매번 for루프를 돌려야 했습니다.  
    - 이처럼 자료구조를 제대로 몰라서 어떤 특성을 활용해야 하는지 평가하고 판단하지 않아 코드가 지나치게 복잡해졌고  
      결국에는 3주 가량 만들어놓은 코드를 전부 갈아엎어야 했습니다.  

### 2. 평가 피드백  

<img width="684" alt="스크린샷 2024-12-27 오후 4 27 22" src="https://github.com/user-attachments/assets/0ea031e2-4e00-4cdc-be7a-927bcc11dda8" />

### 3. 프로젝트 개요  
  1. 인자로 들어온 요소가 5개 이하일 경우에는 경우의 수를 활용한 하드코딩으로 정렬  
  2. 5개를 넘어설 경우 stack a에는 피벗만 남겨놓고 stack b에 각 집단을 큰 순으로 정렬  
![KakaoTalk_Photo_2023-08-05-14-52-43](https://github.com/user-attachments/assets/91b2ebfb-f2ee-495e-82f3-6dee05aaa7c3)
  3. stack a에 남겨놓은 pivot들을 stack b에 작은 순으로 정렬
![KakaoTalk_Photo_2023-08-05-14-53-56](https://github.com/user-attachments/assets/5e5e67b3-183b-480b-9fd9-d810fac60ae2)
  4. stack b에 정렬된 pivot들을 다시 큰 순으로 stack a에 정렬
![KakaoTalk_Photo_2023-08-05-15-04-53](https://github.com/user-attachments/assets/b1a1ad78-13b1-4b57-95cf-17c762d2f87d)
  5. b -> a로 요소를 옮기는 데는 아래의 알고리즘 적용
![Untitled](https://github.com/user-attachments/assets/36d9805a-74d8-431c-a750-ea66efe8e162)

 



