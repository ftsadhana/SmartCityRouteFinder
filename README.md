# Smart City Route Finder

## 📌 Project Overview
Smart City Route Finder is a C-based application that helps users find the shortest route between different locations in a city. It uses **Dijkstra's Algorithm** to calculate the shortest distance based on the road distances entered by the user.

## 🎯 Objectives
- To find the shortest path between two city locations.
- To calculate the total distance of a route.
- To manage road connections and distances.
- To provide a simple, menu-driven interface for users.

## ✨ Features
- Display available city locations.
- Add roads and distances between locations.
- Find the shortest route between two locations.
- Display the total distance in kilometres.
- Handle invalid location numbers and unavailable routes.
- Simple console-based interface.

## 🛠️ Technologies Used
- **Programming Language:** C
- **Algorithm:** Dijkstra's Shortest Path Algorithm
- **Compiler:** GCC
- **Editor:** Visual Studio Code

## 📍 Available Locations
1. Central Bus Stand
2. Railway Station
3. Airport
4. City Hospital
5. College
6. Shopping Mall

## ⚙️ How It Works
1. The user selects an option from the main menu.
2. The user adds roads and distances between locations.
3. The program represents road connections using an adjacency matrix.
4. Dijkstra's Algorithm calculates the shortest available route.
5. The program displays the route and total distance.

## ▶️ How to Run the Project

### 1. Compile the program
```bash
gcc main.c -o route_finder
```

### 2. Run the program on Windows PowerShell
```powershell
.\route_finder.exe
```

**Requirement:** GCC must be installed and configured correctly on your system.

## 🖥️ Menu Options
1. Display Available Locations
2. Add Road and Distance
3. Find Shortest Route
4. Exit

## 🔮 Future Enhancements
- Integrate real-time map data.
- Add more city locations and road connections.
- Develop a graphical user interface.
- Include traffic information for route planning.
- Display routes on a digital map.

## 👩‍💻 Project Status
This is a console-based C project for learning and demonstrating shortest-path algorithms.

## 📄 License
This project is available for educational purposes.
