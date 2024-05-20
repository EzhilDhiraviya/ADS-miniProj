import networkx as nx
import matplotlib.pyplot as plt

# Define the edges of the graph
edges = [
    (0, 1), (0, 15), (1, 2), (0, 14), (15, 16), (15, 12), (15, 14),
    (14, 13), (13, 12), (11, 12), (11, 2), (2, 3), (11, 10), (2, 4),
    (10, 4), (10, 7), (7, 4), (4, 5), (5, 6), (7, 8), (9, 8),
    (1, 14), (9, 15), (13, 15)
]

# Create an empty graph
G = nx.Graph()

# Add edges to the graph
G.add_edges_from(edges)

# Draw the graph
plt.figure(figsize=(10, 8))
nx.draw(G, with_labels=True, node_size=700, node_color="skyblue", font_size=15, font_weight="bold", edge_color="gray")
plt.title("Graph Representation")
plt.show()
