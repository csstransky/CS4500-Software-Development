# Designing a KV Store

Util: (on the side)
+ String
+ Array
+ List 
+ Map

Applications:
+ WordCount

Client:
+ DataFrame
+ Column
+ ColumnChunk

Store:
+ Key
+ Value

KV Store:
+ Messge
+ Network



Node0
Reads file input
Key("data") ->      DF(0)
Key("data-c0") ->   C<S>(0)
Key("data-c0-1") -> C<S>(0,1) // column chunk
Key("data-c0-1") -> C<S>(0,4)

Node1
C<S>(0,2)
C<S>(0,5)

Node2
C<S>(0,3)

+ application parent
    - Has a network connection
    - has a kv store

+ make a key without a node-index, default = 0
+ they make a FileReader visitor that extends a Writer class, that extends a Rower class
+ local_map will only access local chunks of a column
+ delete DataFrame::fromVisistor(mk_key(index), &kv, "SI", cnt);

Key* mk_key(size_t index) { return kbuf.c(index).get(); }

void local_count() {
    DataFrame* words = kv.wait_and_get(in);
    printf("node stuff");
    SIMap map;
    Adder add(map);
    words->local_map(add); // fills the map inside "add" with only local stuff in kv store
    delete words;
    Summer cnt(map); // mainly used to push stuff into a "SI" dataframe
    delete DataFrame::from_visitor(mk_key(index), &kv, "SI", cnt);
}

void reduce() {
    if (index != 0) return;
    printf("Node 0, continuing");
    SIMap map;
    Key* own = mk_key(0); // the result will always exist, unless it doesn't
    merge(kv.get(*own), map); // gets node0's stuff and throw into map
    for (size_t i = 1; i < arg.num_nodes; i++) {
        Key* ok = mk_key(i);
        merge(kv.wait_and_get(*ok), map); // get other dude's stuff, and throw into map
        delete ok;
    }
    printf("Map stuff: %d", map.size());
    delete own;
}

void merge(DataFrame* df, SIMap& m) {
    Adder add(m);
    df->map(add);
    delete df;
}




