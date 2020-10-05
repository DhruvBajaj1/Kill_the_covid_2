# Kill_the_covid_2
## Correct Solution of Kill the Covid problem
#### Problem statement
https://docs.google.com/document/d/1nau-A04ZEBmeC3wfzCj1WBK4edYol2De6BadBlyyPE0/edit?usp=sharing

1. Hexagon Class : It contains name of Hexagon and an array of pointers where each pointer points to one of its neighboring 6 Hexagons if present, otherwise points to NULL.
2. addHexagon Method: It creates a new Hexagon with the specified name, find its neighbors depending upon its co-ordinates and then update all the neigbors i.e, all the neighbors now have this new Hexagon as their neighbor.
The center of the first hexagon added is considered to be (0,0) and the center of other hexagons are calculated with respect to (0,0).
3. getNeighbors Method: It prints all the neighbors of the Hexagon whose name is given.This is implemented by using the array of pointers to Hexagon that each Hexagon node contains.
4. removeHexagon Method: It makes sure that all its neighbors no longer have it as a neighbor and then delete the Hexagon if its deletion does not increase the number of clusters.
If its deletion is resulting in two or more clusters then deletion is not possible in that case.
###Diagram 1.4
![Diagram 1 4](https://user-images.githubusercontent.com/72250554/95115673-7b7edb00-0763-11eb-889f-9647b33d1bcc.JPG)

### Making diagram 1.4 (Only one neighbor specified)
![Making diagram 1 4](https://user-images.githubusercontent.com/72250554/95115117-93099400-0762-11eb-9a24-967f94cd2122.JPG)
![Making diagram (b)1 4](https://user-images.githubusercontent.com/72250554/95115170-aae11800-0762-11eb-9440-0913282e337b.JPG)

### Query for neighbors

![Query for neighbors](https://user-images.githubusercontent.com/72250554/95115271-cfd58b00-0762-11eb-8e50-2431e3ad9f82.JPG)

### Deletion case 1

Deleting Z when N is there between C and E.
In this case deletion is successful as after deletion also, there exists a single cluster.

![Deletion Case 1](https://user-images.githubusercontent.com/72250554/95115437-188d4400-0763-11eb-8e30-b1e33b831643.JPG)

### Deletion case 2

Deleting Z when N is not there
In this case Z will not be deleted as deleting it results in more than 1 cluster.

Number of clusters are found out using dfs.
![Deletion Case 2](https://user-images.githubusercontent.com/72250554/95115585-59855880-0763-11eb-896a-bbe3c77228df.JPG)
