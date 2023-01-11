struct simbol{
	char* nume;
	struct Tip_Date* tip;
	char* valoare;
};
struct list{
	char* dimensiune[20];
	int nr_dimensiuni;
};
struct tabela_simboluri {
	struct simbol entries[100];
	unsigned int nr_entries;
};
struct Tip_Date {
	struct list* size;
    int is_const;
	char* tip;
};
struct functie {
	char* name;
	struct Tip_Date* return_type;
	struct simbol* param[10];
	int nr_param;
};
struct tabela_functii {
	struct functie entries[100];
	unsigned int nr_entries;
};
struct UserDef {
	char* nume;
	struct tabela_simboluri* date;
};
enum Types {OP, IDENTIFIER, INT, STR, CHR, BOL, FLT, FNC};
struct AstNode {
	struct AstNode* Left, *Right;
	int valoare;
	int tip;
};
static struct tabela_simboluri sy_table;
static struct tabela_simboluri* sym_table;
static struct tabela_functii   fn_table;
static struct list userdef_table;
