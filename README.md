# SkyScrapers Problem

In a grid of 4 by 4 squares you want to place a skyscraper in each square with only some clues - the number of skyscrapers seen from the outside. The following rules should be respected:

- The height of a skyscrapers is between 1 and 4;
- no two skyscrapers in a row or column may have the same number of floors;
- a clue is the number of skyscrapers that you can see in a row or column from the outside (see the examples below);
- higher skyscrapers block the view of lower skyscrapers located behind them;
- some clues are not available (any number can be possible).

#### Example: 
the box of size 3 here hides the box of height 1, which implies that from the left only 3 boxes are visible. From the right, the box of height 4 hides the other boxes, so there is only one box visible.

![1.png](/img/1.png)

Each view (two per row and two per column) will have a certain value, ranging from 1 to 4. Your programme must place the boxes correctly, taking care not to have more than one box of each height on each line and column. Your proposal must contain the first solution you find.

The program will be executed as follows:
```
> ./rush-01 "col1up col2up col3up col4up col1down col2down col3down col4down row1left row2left
row3left row4left row1right row2right row3right row4right"
```

The following is an artist's rendering of your programme

![2.png](/img/2.png)

col1up corresponds to the value for the viewpoint from the top of the left-hand column. left-hand column. Each of these represents a character string of values with a range between 1 and 4.

#### Example:
Here is an example of expected input/output for a valid set:

```
>./rush-01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2" | cat -e
1 2 3 4$
2 3 4 1$
3 4 1 2$
4 1 2 3$
```
Representation of the programme execution with col_up, col_down, row_left and row_right

![3.png](/img/3.png)

By replacing the col* and row*, you get this.

![4.png](/img/4.png)