# rush01
On a 4 by 4 map, place the squares between 1 and 4 high so that each line and column shows the correct number of squares from each viewpoint. Each line and column the correct number of squares is visible from every possible viewpoint (left/right for lines and up/down for columns). Example: the box of size 3 here hides the box of height 1, which implies that from the left only 3 boxes are visible. From the right, the box of height 4 hides the other boxes, so there is only one box visible.
![1.jpg](/img/1.jpg)
Each view (two per row and two per column) will have a certain value, ranging from 1 to 4. Your programme must place the boxes correctly, taking care not to have more than one box of each height on each line and column. Not to have more than one box of each height on each line and column. Your proposal must contain the first solution you find.
The program will be executed as follows:
```
> ./rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left
row3left row4left row1right row2right row3right row4right"
```
The following is an artist's rendering of your programme
![2.jpg](/img/2.jpg)
col1up corresponds to the value for the viewpoint from the top of the left-hand column. left-hand column. Each of these represents a character string of values with a range between 1 and 4.
- Here is an example of expected input/output for a valid set:
```
>./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
1 2 3 4$
2 3 4 1$
3 4 1 2$
4 1 2 3$
```
Representation of the programme execution with col_up, col_down, row_left and row_right
![3.jpg](/img/3.jpg)
By replacing the col* and row*, you get this.
![4.jpg](/img/4.jpg)
