struct DSU { // complexity: O(alpha(n)) ~ O(1)
    vector<int> parent, size, rank;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }

    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]); // path compression
    }

    //  Union por tamano
    void unir_size(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    //  Union por rank
    void unir_rank(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b]; // opcional, solo para consultas
            if (rank[a] == rank[b]) rank[a]++;
        }
    }

    bool same(int a, int b) {
        return find(a) == find(b);
    }

    int get_size(int a) {
        return size[find(a)];
    }
};