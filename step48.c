#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 9999
#define MAX_PLACES 6
#define MAX_BOOKS 5

// 1. 그래프 연결 정보 (이름)
const char* placeNames[MAX_PLACES] = {
    "입구(로비)", "인문사회 자료실", "자연과학 자료실", 
    "문학 자료실", "열람실", "휴게실"
};

// 1. 그래프 연결 정보: [인접 행렬]
int adjMatrix[MAX_PLACES][MAX_PLACES] = {
    {  0,   2,   4, INF, INF, INF}, // 0: 입구
    {  2,   0, INF,   3, INF, INF}, // 1: 인문사회
    {  4, INF,   0,   1,   5, INF}, // 2: 자연과학
    {INF,   3,   1,   0, INF,   2}, // 3: 문학
    {INF, INF,   5, INF,   0,   1}, // 4: 열람실
    {INF, INF, INF,   2,   1,   0}  // 5: 휴게실
};

// 2. 탐색할 데이터: [도서 구조체 배열]
typedef struct {
    char title[50];  // 도서명
    int roomNumber;  // 자료실 번호
} Book;

Book bookDatabase[MAX_BOOKS] = {
    {"C언어정석", 2},
    {"노인과바다", 3},
    {"사피엔스", 1},
    {"이기적유전자", 2},
    {"정의란무엇인가", 1}
};

// [이진 탐색 알고리즘]
int binarySearch(Book books[], int n, char* targetTitle) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(books[mid].title, targetTitle);
        
        if (cmp == 0) return books[mid].roomNumber;
        if (cmp < 0) left = mid + 1;
        else right = mid - 1;
    }
    return -1; // 실패 시 -1 반환
}

// 실제 이동 경로 출력을 위한 재귀 함수 (이전 정점 배열 활용)
void printPath(int prevNode[], int current) {
    if (prevNode[current] == -1) {
        printf("%s", placeNames[current]);
        return;
    }
    printPath(prevNode, prevNode[current]);
    printf(" -> %s", placeNames[current]);
}

// [그래프 알고리즘: 다익스트라]
void findShortestPath(int start, int target) {
    // 3. 알고리즘 보조 데이터
    int dist[MAX_PLACES];       // 거리 배열
    bool visited[MAX_PLACES];   // 방문여부 배열
    int prevNode[MAX_PLACES];   // 이전 정점 배열 (경로 역추적용)

    // 보조 데이터 초기화
    for (int i = 0; i < MAX_PLACES; i++) {
        dist[i] = INF;
        visited[i] = false;
        prevNode[i] = -1;
    }
    dist[start] = 0;

    // 다익스트라 핵심 로직
    for (int count = 0; count < MAX_PLACES - 1; count++) {
        int min = INF, u = -1;
        
        // 방문하지 않은 정점 중 최단 거리가 가장 짧은 정점 선택
        for (int v = 0; v < MAX_PLACES; v++) {
            if (!visited[v] && dist[v] < min) {
                min = dist[v];
                u = v;
            }
        }
        if (u == -1) break;
        visited[u] = true;

        // 선택된 정점을 거쳐가는 인접 정점들의 거리 갱신
        for (int v = 0; v < MAX_PLACES; v++) {
            // 인접 행렬(adjMatrix)을 확인하여 갱신 조건 판단
            if (!visited[v] && adjMatrix[u][v] != INF && dist[u] + adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + adjMatrix[u][v];
                prevNode[v] = u; // 갱신 시 이전 정점 배열에 기록
            }
        }
    }

    // 결과 출력
    printf("\n[검색 및 길안내 결과]\n");
    printf("- 도서가 있는 자료실: %s\n", placeNames[target]);
    printf("- 최소 이동 시간: %d분\n", dist[target]);
    
    printf("- 실제 이동 경로: ");
    if (start == target) {
        printf("현재 위치에 있습니다.\n");
    } else {
        printPath(prevNode, target);
        printf("\n");
    }
}

int main() {
    int currentLocation;
    char searchBook[50];

    printf("현재 위치 번호를 입력하세요 (0:입구, 1:인문사회, 2:자연과학, 3:문학, 4:열람실, 5:휴게실): ");
    scanf("%d", &currentLocation);

    if (currentLocation < 0 || currentLocation >= MAX_PLACES) {
        printf("잘못된 위치 번호입니다.\n");
        return 0;
    }

    printf("검색할 도서명을 입력하세요 (띄어쓰기 없이): ");
    scanf("%s", searchBook);

    int targetRoom = binarySearch(bookDatabase, MAX_BOOKS, searchBook);

    if (targetRoom == -1) {
        printf("\n해당 도서를 찾을 수 없습니다.\n");
    } else {
        findShortestPath(currentLocation, targetRoom);
    }

    return 0;
}