# push_swap
# Push_Swap

<p align="center">
  <img src="https://img.shields.io/badge/42-Push_Swap-darkgreen" alt="42 Push_Swap"/>
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language C"/>
</p>

## 📋 Overview

`push_swap` is a 42 School algorithm project focused on data sorting optimization. The challenge is to sort a stack of integers using a limited set of operations with the minimum number of moves.

Working with only two stacks (A and B) and a specific set of actions, the goal is to write a program that calculates and displays the smallest sequence of operations needed to sort the stack of integers.

## 🔍 The Rules

### Data Structure

- **Stack A**: Contains a random list of integers (no duplicates allowed)
- **Stack B**: Empty at the beginning

### Available Operations

- `sa`: swap the first 2 elements at the top of stack A
- `sb`: swap the first 2 elements at the top of stack B
- `ss`: `sa` and `sb` at the same time
- `pa`: take the first element at the top of B and put it at the top of A
- `pb`: take the first element at the top of A and put it at the top of B
- `ra`: rotate stack A (first element becomes last)
- `rb`: rotate stack B (first element becomes last)
- `rr`: `ra` and `rb` at the same time
- `rra`: reverse rotate stack A (last element becomes first)
- `rrb`: reverse rotate stack B (last element becomes first)
- `rrr`: `rra` and `rrb` at the same time

## 🚀 Installation

Clone the repository and compile the program:

```bash
git clone https://github.com/yourusername/push_swap.git
cd push_swap
make
```

## 💻 Usage

### Push_Swap Program

```bash
./push_swap [list of integers]
```

Example:
```bash
./push_swap 5 2 9 1 3
```

This will display the list of operations to sort the stack.

### Checker Program (if implemented)

```bash
./checker [list of integers]
```

Example with pipe:
```bash
ARG="5 2 9 1 3"; ./push_swap $ARG | ./checker $ARG
```

## 🧠 Algorithm

The project implements a custom sorting algorithm that efficiently sorts integers with a limited set of operations. My implementation uses:

- **Stack analysis** to determine optimal sorting strategies
- **Chunking technique** to handle large datasets
- **Cost calculation** for operation minimization 
- **Optimized rotation** to reduce moves

## ⚙️ Implementation Details

### Stack Structure

```c
typedef struct s_stack
{
    int             *numbers;
    int             size;
    int             capacity;
} t_stack;
```

### Sorting Strategy

For small sets (≤5 numbers):
- Specialized algorithms for each size

For large sets:
- Chunk-based approach
- Cost-optimized moves
- Targeted insertion

## 📊 Performance

Performance targets for different input sizes:

| Input Size | Target Operations |
|------------|-------------------|
| 3 numbers  | ≤ 3 operations    |
| 5 numbers  | ≤ 12 operations   |
| 100 numbers| < 700 operations  |
| 500 numbers| < 5500 operations |

## 🔧 Optimization Techniques

- Identifying and eliminating redundant operations
- Pre-sorting analysis to determine best approach
- Careful selection of pivot elements
- Combined operations (like `ss`, `rr`) when beneficial

## 🎨 Visualization

To visualize the sorting process, you can use external tools like:

- [push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)
- [push-swap-gui](https://github.com/elijahkash/push_swap_gui)

Example:
```bash
./push_swap 5 2 9 1 3 | ./visualizer
```

## 📝 Notes

- Handling large datasets efficiently requires careful algorithm design
- The project is extremely useful for understanding sorting complexity and optimization
- Memory management in C is critical for this project's success

## 🤝 Contributing

Feel free to submit issues or pull requests if you have suggestions for improvements!

## 📜 License

This project is part of the 42 School curriculum and is for educational purposes.

---

*Created by **[your_username]** - Feel free to contact me for any questions!*
