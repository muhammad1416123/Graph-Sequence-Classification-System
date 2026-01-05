# Graph Sequence Classification

## Project Overview

This project implements a **Graph Sequence Classification system** that analyzes a given sequence of vertices (cities) and determines its classification according to standard graph theory definitions.

Given a graph and a sequence of vertices, the system checks whether the sequence forms a **walk, trail, path, closed walk, circuit, or simple circuit** based on edge and vertex repetition rules.

---

## Author

- **Muhammad Bin Shahid**

---

## Problem Description

In graph theory, sequences of vertices can represent different structures depending on how edges and vertices are used. This project provides a structured and correct way to classify such sequences by validating them against formal definitions.

The system assumes:
- The graph is already loaded
- All vertices in the sequence exist in the graph
- The sequence length is at least one

---

## Implemented Functions

### `isWalk(seq, len)`
- Returns true if every consecutive pair of vertices has a connecting edge.

### `isTrail(seq, len)`
- Returns true if the sequence is a walk and no edge is repeated.

### `isPath(seq, len)`
- Returns true if the sequence is a walk and no vertex is repeated.

### `isClosedWalk(seq, len)`
- Returns true if the sequence is a walk and starts and ends at the same vertex.

### `isCircuit(seq, len)`
- Returns true if the sequence is a closed walk with no repeated edges.

### `isSimpleCircuit(seq, len)`
- Returns true if the sequence is a closed walk with no repeated vertices except the start and end vertex.

All functions are **total and correct**, using finite checks and preserving the input sequence.

---

## How It Works

1. The user enters a sequence of vertices in order.
2. The system validates edge connectivity between consecutive vertices.
3. Additional checks are applied to detect repeated edges or vertices.
4. The sequence is classified into applicable graph categories.
5. Results are displayed clearly for each classification type.

---

## Sample Classifications

The system can correctly identify:
- Simple paths
- Walks with repeated vertices
- Trails with unique edges
- Closed walks
- Circuits and simple circuits
- Invalid sequences where edges do not exist

---

## Learning Outcomes

- Practical application of graph theory concepts
- Understanding differences between walks, trails, paths, and circuits
- Writing formally correct and total logical functions
- Input validation and classification logic

---

## Conclusion

This project provides a reliable and structured solution for classifying graph sequences. It accurately applies theoretical definitions in a practical implementation, making it useful for learning, testing, and demonstrating graph theory concepts.

---

## References

- Discrete Mathematics (Graph Theory)
- Standard definitions of walks, trails, paths, and circuits
