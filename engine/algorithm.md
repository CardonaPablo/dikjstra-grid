# Dijkstra

## 1. Generating the graph with barriers

Let the grid be a n x n matrix
Representing the graph as a matrix representing the links

1 2 3
4 5 x
7 8 9

  i
j   1 2 3 4 5 6 7 8 9
  1 0 1 0 1 0 0 0 0 0 
  2 1 0 1 0 1 0 0 0 0 
  3 0 1 0 0 0 0 0 0 0
  4 1 0 0 0 1 0 1 0 0
  5 0 1 0 1 0 0 0 1 0 
  6 0 0 0 0 0 0 0 0 0
  7 1 0 0 1 0 0 0 1 0
  8 0 0 0 0 1 0 1 0 1
  9 0 0 0 0 0 0 0 1 0

Inside of a nested for ( i -> j)
The letter i represents the source cell
The letter j represents the target cell

We should put a 1 when j is one of:
- j is i - 1: The left cell
	Except when j is al multiple of dimension (j%dimension is 0) 
- j is i + 1: the right cell
	Except when i is al multiple of dimension (i%dimension is 0) 
- j is i + dimension: Lower cell
- j is i - dimension: Upper cell

Except when the cell number is included in barriers, that way, it cant connect
- When i or j are included in the barriers array, fill with zeros

### Removing unconnected nodes (removed)
If a row is filled with 0, we can assume that also the i position of the row is a 0
- Go through each row i and remove the element in the i position


# 2. Dikjstra
Let the graph be a matrix 

 i
j  a b c d e z
 a 0 3 4 0 0 0 
 b 3 0 0 6 5 0
 c 4 0 0 0 1 0
 d 0 6 0 0 2 7
 e 0 5 1 2 0 12
 z 0 0 0 7 12 0

## Global Variables
V(T) = visited nodes: `vector<int> visited = ['startNode.id']`
E(T) = checked paths: `vector<pair<int, int>> paths`
F = possible paths for a node n from the  starting node: `vector<int> potentialJumps`
F(n) = = possible direct paths from a node n: `getDirectJumps(node)` calculated from the graph matrix
L = `vector<int> minLenghts(n, n*n)`
L(n) = minLenght = min lenght of a node n: `minLenghts.get(n)`

## Updating the minWeight
- In the first iteration we populate with the initial weight:
```
L(b) = 3
L(c) = 4
```
- 2nd iteration: we are currently in b, we get the direct jumps and to calculate the weight add the direct weight (d ->6) to the current node (b->3)weight to get (d min. 9)
```
L(b) = 3
L(c) = 4
L(d) = 3 + 6 = 9
L(e) = 3 + 5 = 8
```
- 3rd iteration: we are in c, the direct jumps are e, so we need to calculate current weight (e -> 1) + (c->4) = (e -> 5)
If this number is lower than whats currently stored in (e -> 8) replace the value
```
L(b) = 3
L(c) = 4
L(d) = 9
L(e) = 4 + 1 = 5
```
- 4th iteration: 
We are in e, direct jumps: b, d, z
Since b is in the visited we do not count it
D is not, so we do (d->2) to (e -> 5) and compare (d->7) < (d->9), and select 7
We add z as (z-> e +z = 17)

- Conclusion:
Start with a vector of the graph dimension filled with a max number
Each iteration
1. Get the direct jumps of the current node
2. Ignore the ones present in the `visited`
3. Check for one of this cases
  - The node is alredy present in `potentialJumps`:
    Calculate the new weight: current.weight + jump.weight 
    If is lower than the current node.weight replace the value
  - The node is not present in `potentialJumps`:
    Calculate the new weight: current.weight + jump.weight 


## General algorithm
- Start in the row corresponding to the starting point and add it to the visited array `visited.push(a)`
- **Update minWeight**
- Select the lowest weighted connection in the `minLenghts` array that not appears in visited: b -> 3
- Add the path to `paths` array: `paths.push({a,b})`
- Add the node to the visited array: `visited.push(b)`

- Go to the row corresponding to the selected node: b
- Add to `potentialJumps` the `directJumps` nodes and remove the elements contained in the `visited` nodes: 
- **Update minWeight**
- Select the lowest value from the `minWeights` array excluding the current node: L(c) = 4
- Add the path to `paths` array: `paths.push({a,c})`
- Add the node to the visited array: `visited.push(c)`

- Go to the row corresponding to the selected node: c
- Add to `potentialJumps` the `directJumps` nodes and remove the elements contained in the `visited` nodes: 
- **Update minWeight**
- Select the lowest value from the `minWeights` array excluding the current node: L(e) = 5
- Add the path to `paths` array: `paths.push({c,e})`
- Add the node to the visited array: `visited.push(e)`

- Stop when:
  - The `potentialJumps` array consists only of the final node (path found)
  - The `potentialJumps` array is empty (no solution)
 

## If a path is found, analize the way back via tuples
- Start with the tuple which second attribute is the final node
- Search in the previous nodes for a node where the current.first attribute is equal to node.second attribute
- Store the current.second attribute in an array 
- If the current.first attribute is the start node, stop and add current.first to the array
- Reverse the array
- the final array will have the complete path from start to finish