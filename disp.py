import networkx as nx
import matplotlib.pyplot as plt
import os  # Import the os module to execute system commands

# Define edges
edges = [(1, 2), (2, 3), (3, 4), (4, 1)]

# edges = []
# with open('edge.txt', 'r') as file:
#     for line in file:
#         edge = tuple(map(int, line.strip().split(',')))
#         edges.append(edge)

# Define positions for the nodes
node_positions = {
    1: (-5, 0),
    2: (1, 1),
    3: (2, 0),
    4: (0, 5)
}

# node_positions = {}
# with open('node.txt', 'r') as file:
#     for line in file:
#         node, x, y = map(int, line.strip().split())
#         node_positions[node] = (x, y)

# Create a graph
G = nx.Graph()

# Add edges to the graph
G.add_edges_from(edges)

# Draw the graph with nodes represented in blue and fixed positions
nx.draw(G, pos=node_positions, with_labels=True, node_color='blue', font_color='white')

# Save the graph visualization as an image
plt.savefig('graph_visualization.png')

# Close the plot to avoid displaying it
plt.close()

# Open the generated image file using the default application
os.system('start graph_visualization.png')  # For Windows
# Alternatively, for Unix-based systems like Linux or macOS:
# os.system('xdg-open graph_visualization.png')
