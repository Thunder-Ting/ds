#include <iostream>
#include <vector>
#include <climits>
#include <cstdio>
#include <algorithm>

const int INF = 1e9; // ��ʾ��������֮��û�б�

//���ڵ����õ� start
#ifdef _WIN32

#include <windows.h>

#endif

void setGreen() {
#ifdef _WIN32
    // Windows-specific code to set text color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
#else
    std::cout << "\033[0;32m";
#endif
}

void resetColor() {
#ifdef _WIN32
    // Windows-specific code to reset text color
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
#else
    std::cout << "\033[0m";
#endif
}

#define LOG_VECTOR(name, nums) log(#name, nums)
//���ڵ����õ� end

// ��Ȩ������ͼ
class Graph {
public:
    Graph(int vertices) : vertices(vertices) {
        // ��ʼ���ڽӾ���
        adjMatrix = std::vector<std::vector<int>>(vertices, std::vector<int>(vertices, INF));
        for (int i = 0; i < vertices; ++i) {
            adjMatrix[i][i] = 0; // �Լ����Լ��ľ�����0
        }
    }

    void addEdge(int u, int v, int weight) {
        // ��������
        u -= 1;
        v -= 1;
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;
    }

    void printGraph() {
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                if (adjMatrix[i][j] == INF) {
                    printf("%-5s", "INF");
                } else {
                    printf("%-5d", adjMatrix[i][j]);
                }
            }
            printf("\n");
        }
    }

    void primMST() {
        std::vector<int> key(vertices, INF);  // �洢ÿ������ļ�ֵ����С��Ȩ�أ�
        std::vector<int> parent(vertices, -1); // �洢��С�������ĸ��ڵ�
        std::vector<bool> inMST(vertices, false); // ��Ƕ����Ƿ�����С��������

        key[0] = 0; // ��ʾ��ʼ���㣨���� 0�����Լ����ӵ�Ȩ���� 0
        for (int count = 0; count < vertices - 1; ++count) {
            //������δ�������� MST �еĶ��㣬�ҵ� key ֵ��С�Ķ��� (minIndex)��
            int minKey = INF, minIndex;
            for (int v = 0; v < vertices; ++v) {
                LOG_VECTOR(key, key);
                LOG_VECTOR(parent, parent);
                printf("\n");
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    minIndex = v;
                }
            }

            // �� minIndex ������Ϊ�Ѿ������� MST ��
            inMST[minIndex] = true;

            // Update the key value and parent index of the adjacent vertices
            for (int v = 0; v < vertices; ++v) {
                if (adjMatrix[minIndex][v] && !inMST[v] && adjMatrix[minIndex][v] < key[v]) {
                    parent[v] = minIndex;
                    key[v] = adjMatrix[minIndex][v];
                }
            }
        }

        // Print the constructed MST
//        printMST(parent);
    }

private:
    int vertices;
    std::vector<std::vector<int>> adjMatrix;

    void printMST(const std::vector<int> &parent) {
        std::cout << "Edge \tWeight\n";
        for (int i = 1; i < vertices; ++i) {
            std::cout << parent[i] + 1 << " - " << i + 1 << " \t" << adjMatrix[i][parent[i]] << " \n";
        }
    }

    void log(const char *name, const std::vector<int> &nums) const {
        setGreen();
        printf("%s[ ", name);
        for (auto elem: nums) {
            if (elem == INF) {
                printf("%-5s", "INF");
            } else {
                printf("%-5d", elem);
            }
        }
        printf(" ]\n");
        resetColor();
    }
};