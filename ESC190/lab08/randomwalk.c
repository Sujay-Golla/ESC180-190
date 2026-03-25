#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node **neighbours;   // array of pointers to neighbour nodes
    int num_neighbours;
    int capacity;               // allocated size of neighbours array
} node;

typedef struct graph {
    node **nodes;               // array of pointers to nodes
    int num_nodes;
} graph;

node *create_node(int data)
{
    node *n = (node *)malloc(sizeof(node));
    n->data = data;
    n->num_neighbours = 0;
    n->capacity = 4;
    n->neighbours = (node **)malloc(n->capacity * sizeof(node *));
    return n;
}

graph *create_graph()
{
    graph *g = (graph *)malloc(sizeof(graph));
    g->num_nodes = 0;
    g->nodes = NULL;
    return g;
}

void add_neighbour(node *n, node *neighbour)
{
    if (n->num_neighbours == n->capacity) {
        n->capacity *= 2;
        n->neighbours = (node **)realloc(n->neighbours,
                                          n->capacity * sizeof(node *));
    }
    n->neighbours[n->num_neighbours] = neighbour;
    n->num_neighbours++;
}

void add_node(graph *g, node *n)
{
    g->num_nodes++;
    g->nodes = (node **)realloc(g->nodes, g->num_nodes * sizeof(node *));
    g->nodes[g->num_nodes - 1] = n;
}

int random_step(graph *g, int current)
{
    int index = -1;
    for (int i = 0; i < g->num_nodes; i++) {
        if (g->nodes[i]->data == current) {
            index = i;
            break;
        }
    }
    return g->nodes[index]->neighbours[rand() % g->nodes[index]->num_neighbours]->data;
}

void random_walk(graph *g, int start, int steps)
{
    int current = start;
    printf("%d ", current);
    for (int i = 0; i < steps; i++) {
        current = random_step(g, current);
        printf("%d ", current);
    }
    printf("\n");
}

double *create_transition_matrix(graph *g)
{
    double *matrix = (double *)malloc(g->num_nodes * g->num_nodes * sizeof(double));
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->num_nodes; j++) {
            matrix[i * g->num_nodes + j] = 0.0;
        }
        for (int k = 0; k < g->nodes[i]->num_neighbours; k++) {
            int neighbour_index = -1;
            for (int j = 0; j < g->num_nodes; j++) {
                if (g->nodes[j]->data == g->nodes[i]->neighbours[k]->data) {
                    neighbour_index = j;
                    break;
                }
            }
            matrix[i * g->num_nodes + neighbour_index] += 1.0 / g->nodes[i]->num_neighbours;
        }
    }
    return matrix;
}

void print_matrix(graph *g, double *matrix)
{
    for (int i = 0; i < g->num_nodes; i++) {
        for (int j = 0; j < g->num_nodes; j++) {
            printf("%.2f ", matrix[i * g->num_nodes + j]);
        }
        printf("\n");
    }
}

void mat_vec_mult(double *M, double *v, double *result, int n)
{
    for (int i = 0; i < n; i++) {
        result[i] = 0.0;
        for (int j = 0; j < n; j++) {
            result[i] += v[j] * M[i * n + j];
        }
    }
}

void pagerank(double *M, double *v, int n, int k)
{
    double *temp = malloc(n * sizeof *temp);
    for (int i = 0; i < k; i++) {
        mat_vec_mult(M, v, temp, n);
        for (int j = 0; j < n; j++){
            v[j] = temp[j];
        }
    }
    free(temp);
}

int main(){
    srand(time(NULL));

    node *a = create_node(1);
    node *b = create_node(2);
    node *c = create_node(3);
    node *d = create_node(4);
    node *e = create_node(5);
    node *f = create_node(6);

    add_neighbour(a, b);
    add_neighbour(a, c);
    add_neighbour(b, d);
    add_neighbour(c, d);
    add_neighbour(b, c);
    add_neighbour(a, d);
    add_neighbour(d, e);
    add_neighbour(e, f);
    add_neighbour(f, a);
    add_neighbour(f, d);

    graph *g = create_graph();
    add_node(g, a);
    add_node(g, b);
    add_node(g, c);
    add_node(g, d);
    add_node(g, e);
    add_node(g, f);

    printf("Random Walks:\n");
    random_walk(g, 1, 5);
    random_walk(g, 1, 5);
    random_walk(g, 1, 5);
    random_walk(g, 1, 5);
    random_walk(g, 1, 5);

    printf("\nTransition Matrix:\n");

    node *w = create_node(0);
    node *x = create_node(1);
    node *y = create_node(2);
    node *z = create_node(3);

    add_neighbour(w, x);
    add_neighbour(w, y);
    add_neighbour(x, y);
    add_neighbour(y, w);
    add_neighbour(y, z);
    add_neighbour(z, w);

    graph *g2 = create_graph();
    add_node(g2, w);
    add_node(g2, x);
    add_node(g2, y);
    add_node(g2, z);

    double *matrix = create_transition_matrix(g2);
    print_matrix(g2, matrix);

    double *v = (double *)malloc(g2->num_nodes * sizeof(double));
    for (int i = 0; i < g2->num_nodes; i++) {
        v[i] = 1.0 / g2->num_nodes;
    }
    pagerank(matrix, v, g2->num_nodes, 1);
    printf("\nPageRank (1 iterations):\n");
    for (int i = 0; i < g2->num_nodes; i++) {
        printf("Node %d: %.4f\n", g2->nodes[i]->data, v[i]);
    }

    double *v2 = (double *)malloc(g2->num_nodes * sizeof(double));
    for (int i = 0; i < g2->num_nodes; i++) {   
        v2[i] = 1.0 / g2->num_nodes;
    }
    pagerank(matrix, v2, g2->num_nodes, 5);
    printf("\nPageRank (5 iterations):\n");
    for (int i = 0; i < g2->num_nodes; i++) {
        printf("Node %d: %.4f\n", g2->nodes[i]->data, v2[i]);
    }

    double *v3 = (double *)malloc(g2->num_nodes * sizeof(double));
    for (int i = 0; i < g2->num_nodes; i++) {
        v3[i] = 1.0 / g2->num_nodes;
    }
    pagerank(matrix, v3, g2->num_nodes, 10);
    printf("\nPageRank (10 iterations):\n");
    for (int i = 0; i < g2->num_nodes; i++) {
        printf("Node %d: %.4f\n", g2->nodes[i]->data, v3[i]);
    }

    double *v4 = (double *)malloc(g2->num_nodes * sizeof(double));
    for (int i = 0; i < g2->num_nodes; i++) {
        v4[i] = 1.0 / g2->num_nodes;
    }
    pagerank(matrix, v4, g2->num_nodes, 20);
    printf("\nPageRank (20 iterations):\n");
    for (int i = 0; i < g2->num_nodes; i++) {
        printf("Node %d: %.4f\n", g2->nodes[i]->data, v4[i]);
    }
}