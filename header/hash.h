#ifndef HASHHEADER
#define HASHHEADER

struct CString {
	char *value;
	int length;
	int hash_code;
};

struct CInteger {
	int value;
	int hash_code;
};

struct CDouble {
	double value;
	int hash_code;
};

struct CLong {
	long value;
	int hash_code;
};

struct CBoolean {
	int value; //1 for true, -1 for false
	int hash_code;
};

int cstring_hash_code(const struct CString* string);
int cinteger_hash_code(const struct CInteger* integer);
int cdouble_hash_code(const struct CDouble* Double);
int clong_hash_code(const struct CLong* Long);
int cboolean_hash_code(const struct CBoolean* boolean);

int char_hash_code(const char c);
int string_hash_code(const char *string);
int int_hash_code(const int value);
int long_hash_code(const long value);
int double_hash_code(const double value);
int float_hash_code(const float value);
#endif
