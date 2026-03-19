# 🌐 Link State Routing Simulation

## 📌 About the Project

This project is a simulation of the **Link State Routing algorithm**, which is used in real-world networking protocols like OSPF.

The idea behind this project is to understand how routers in a network calculate the shortest path to every other router using **Dijkstra’s Algorithm**. Instead of just learning the theory, this project shows how it actually works step by step.

---

## 💡 What this project does

* Lets you create a network of routers (nodes) and links (edges with cost)
* Calculates shortest paths between all nodes
* Builds routing tables for each router
* Simulates how a packet travels from source to destination
* Allows updating link costs dynamically and recalculates routes

---

## 🧠 Concepts used

* Graphs (Adjacency Matrix representation)
* Dijkstra’s Algorithm (Shortest Path)
* Routing Tables
* Link State Routing logic

---

## ⚙️ How it works (simple explanation)

1. First, the network topology is created by taking input from the user (nodes and edges)

2. Then, Dijkstra’s Algorithm is run for each node to calculate shortest paths

3. Each node stores:

   * Minimum cost to every other node
   * Next hop to reach that node

4. The program provides a menu to:

   * Route a packet
   * Update link cost
   * View routing tables
   * Show shortest path

5. If a link is updated, all routing tables are recalculated automatically

---

## 📁 Project Structure

```
main.c        -> Handles user interaction and simulation menu
routing.c     -> Contains core logic (Dijkstra, routing, updates)
routing.h     -> Header file with declarations
```

---

## ▶️ How to run

Compile:

```
gcc main.c routing.c -o simulation
```

Run:

```
./simulation
```

---

## 🧪 Example

You can:

* Create a network with multiple nodes
* Route a packet from one node to another
* Update a link cost and see how paths change

---

## 🔥 What I learned

* How shortest path algorithms are used in real networks
* How routing tables are built and updated
* How dynamic changes affect network routing
* Practical implementation of Dijkstra’s Algorithm

---

## 🚀 Future improvements

* Add a graphical visualization of the network
* Handle larger networks more efficiently
* Add file input instead of manual input

---

