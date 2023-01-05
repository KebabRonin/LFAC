struct simbol{
	char* nume;
	struct Tip_Date* tip;
	char* valoare;
};
struct tabela_simboluri {
	struct simbol entries[300];
	unsigned int nr_entries;
};
struct Tip_Date {
    int is_const;
	char* tip;
};