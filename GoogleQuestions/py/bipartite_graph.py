"""
Question :
Check whether given graph is bipartite.
Constraints :
Graph is undirected (can have multiple components)
"""

"""
Solution Analysis :
Time Complexity : O(v^2) where V is number of vertices
Space Complexity : O(V)
"""

from collections import defaultdict, deque
from typing import Dict, List, Tuple

def is_component_bipartite(src: int, color: List[int], adj_list: Dict[int, List[int]]) -> bool:
    """ Check if component is bipartite using BFS """
    
    bfs_q = deque([src])
    color[src] = 0

    while len(bfs_q) > 0:
        
        u = bfs_q.popleft()

        for v in adj_list[u]:
            if color[v] == -1:
                bfs_q.append(v)
                color[v] = 1 - color[u]
            elif color[v] == color[u]:
                return False
    
    return True


def is_graph_bipartite(n: int, edges: List[Tuple[int,int]]) -> bool:
    """ Check if graph is bipartite by checking bipartiteness for each component"""
    
    adj_list = defaultdict(list)
    color = [-1]*n
    for u, v in edges:
        adj_list[u].append(v)
        adj_list[v].append(u)
    
    for u in range(n):
        if (color[u] == -1) and (not is_component_bipartite(u, color, adj_list)):
            return False
    
    return True


def main():

    # Graph with single and completely connected component (square with diags) is not bipartite
    result = is_graph_bipartite(4, [(0,1), (1,2), (2,3), (3,0), (0,2), (1,3)])
    assert result == False
    
    # Graph without edges is also bipartite
    result = is_graph_bipartite(10, [])
    assert result == True

    # Graph with cycle (even number of vertex) is also bipartite (square)
    result = is_graph_bipartite(4, [(0,1), (1,2), (2,3), (3,0)])
    assert result == True

    # Graph with cycle (odd number of vertex) is  not bipartite (triangle)
    result = is_graph_bipartite(3, [(0,1), (1,2), (0,2)])
    assert result == False

    # Graph with multiple components (square and line)
    result = is_graph_bipartite(6, [(0,1), (1,2), (2,3), (3,0), (4,5)])
    assert result == True

    # Graph with multiple components (square and triangle)
    result = is_graph_bipartite(7, [(0,1), (1,2), (2,3), (3,0), (4,5), (5,6), (4,6)])
    assert result == False


if __name__ == "__main__":
    main()