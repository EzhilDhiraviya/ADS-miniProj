import networkx as nx
import matplotlib.pyplot as plt
import os

# Define edges
edges = []
with open('texts/edges.txt', 'r') as file:
    for line in file:
        edge = tuple(map(int, line.strip().split()))
        edges.append(edge)

# Define positions for the nodes
node_positions = {}
with open('texts/coors.txt', 'r') as file:
    for line in file:
        node, x, y = map(int, line.strip().split())
        node_positions[node] = (x, -y)

# Read node labels from mapping.txt
node_labels = {}
with open('texts/mapping.txt', 'r') as file:
    for line in file:
        node, label = line.strip().split()
        node_labels[int(node)] = label

# Create a graph
G = nx.Graph()

# Add edges to the graph
G.add_edges_from(edges)

# Set the size of the nodes (increase the node size)
node_size = 3600

# Draw the graph with nodes represented in blue and fixed positions, with node labels
plt.figure(figsize=(15, 12))  # Set the figure size
nx.draw(G, pos=node_positions, labels=node_labels, with_labels=True, node_color='blue', font_color='white', node_size=node_size)

# Save the graph visualization as an image
plt.savefig('graph_visualization.png')

# Close the plot to avoid displaying it
plt.close()

# Open the generated image file using the default application
os.system('start graph_visualization.png')  # For Windows
# Alternatively, for Unix-based systems like Linux or macOS:
# os.system('xdg-open graph_visualization.png')
