cmake_minimum_required(VERSION 3.15)
project(AlgorithmReadingNote)

set(CMAKE_CXX_STANDARD 14)

add_executable(AlgorithmReadingNote BinarySearch.cpp BubbleSort.cpp SelectionSort.cpp InsertionSort.cpp MergeSort.cpp QuickSort.cpp Search/BFS_binary_tree.cpp Search/Using_priority_queue.cpp Search/Userdefined_hash_map.cpp Search/Using_hash_map.cpp Dynamic-Programming/rod-cutting.cpp Dynamic-Programming/Longest-increasing-sequence.cpp Search/DFS-NQueen.cpp Search/copydfs.cpp Graph/Prime.cpp Graph/Kruskal.cpp Graph/Bellford.cpp Graph/Dijkstra.cpp)