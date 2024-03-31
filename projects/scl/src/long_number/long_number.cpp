#include "long_number.hpp"

using KSerikov::LongNumber;

LongNumber::LongNumber() : length(1), sign(POSITIVE) {
	numbers = new int[length];
	numbers[0] = 0;
}

LongNumber::LongNumber(int length, int sign) : length(length), sign(sign) {
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = 0;
	}
}

LongNumber::LongNumber(const char* const str) {
	int str_length = get_length(str);
	if (str[0] == MINUS) {
		sign = -1;
		length = str_length - 1;
	}
	else {
		sign = 1;
		length = str_length;
	}

	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - i - 1] - ZERO;
	}
}

LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}
}

LongNumber::LongNumber(LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
}

LongNumber::~LongNumber() {
	length = 0;
	delete[] numbers;
	numbers = nullptr;
}

LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = get_length(str);
	if (str[0] == MINUS) {
		sign = -1;
		length = str_length - 1;
	}
	else {
		sign = 1;
		length = str_length;
	}

	delete[] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = str[str_length - i - 1] - ZERO;
	}

	return *this;
}

LongNumber& LongNumber::operator = (const LongNumber& x) {
	if (this == &x) return *this;

	length = x.length;
	sign = x.sign;

	delete[] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; i++) {
		numbers[i] = x.numbers[i];
	}

	return *this;
}

LongNumber& LongNumber::operator = (LongNumber&& x) {
	length = x.length;
	sign = x.sign;

	delete[] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;

	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (sign != x.sign || length != x.length)
		return false;

	for (int i = 0; i < length; ++i) {
		if (numbers[i] != x.numbers[i])
			return false;
	}

	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	return !(*this == x);
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign > x.sign) return true;
	if (sign < x.sign) return false;

	if (length > x.length) return true;
	if (length < x.length) return false;

	for (int i = length - 1; i >= 0; --i) {
		if (numbers[i] > x.numbers[i])
			return true;
		else if (numbers[i] < x.numbers[i])
			return false;
	}

	return false; // Numbers are equal
}

bool LongNumber::operator < (const LongNumber& x) const {
	return (x > *this);
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	if (sign != x.sign) {
		return (*this) - x;
	}

	int max_length = std::max(length, x.length) + 1;
	int* result = new int[max_length];
	for (int i = 0; i < max_length; ++i) {
		result[i] = 0;
	}

	int carry = 0;
	int result_index = max_length - 1;
	int i = length - 1;
	int j = x.length - 1;

	while (i >= 0 || j >= 0) {
		int sum = carry;
		if (i >= 0) {
			sum += numbers[i];
			i--;
		}
		if (j >= 0) {
			sum += x.numbers[j];
			j--;
		}
		result[result_index] = sum % 10;
		carry = sum / 10;
		result_index--;
	}

	if (carry != 0) {
		result[result_index] = carry;
	}

	int result_length = max_length;
	if (carry == 0) {
		result_length--;
	}

	LongNumber result_number;

	if (carry == 0)
		result_number.sign = POSITIVE;
	else
		result_number.sign = sign;
	result_number.length = result_length;
	result_number.numbers = new int[result_length];

	for (int k = 0; k < result_length; ++k) {
		result_number.numbers[k] = result[result_index + 1 + k];
	}

	delete[] result;

	return result_number;
}


LongNumber LongNumber::operator - (const LongNumber& x) const {
	LongNumber result;
	if (sign != x.sign) {
		result.sign = sign;
	}
	else {
		return *this + x;
	}

	result.length = std::max(length, x.length);
	result.numbers = new int[result.length];

	int borrow = 0;
	for (int i = result.length - 1, j = length - 1, k = x.length - 1; i >= 0; --i, --j, --k) {
		int diff = 0;
		if (j >= 0) diff += numbers[j];
		if (k >= 0) diff -= x.numbers[k];
		diff -= borrow;

		if (diff < 0) {
			diff += 10;
			borrow = 1;
		}
		else {
			borrow = 0;
		}

		result.numbers[i] = diff;
	}

	while (result.length > 1 && result.numbers[0] == 0) {
		for (int i = 0; i < result.length - 1; ++i) {
			result.numbers[i] = result.numbers[i + 1];
		}
		--result.length;
	}

	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	// TODO
	LongNumber result;
	return result;
}

LongNumber LongNumber::operator / (const LongNumber& x) const {
	// TODO
	LongNumber result;
	return result;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	// TODO
	LongNumber result;
	return result;
}

int LongNumber::get_digits_number() const {
	return length;
}

bool LongNumber::is_negative() const {
	return sign == NEGATIVE;
}

int LongNumber::get_length(const char* const str) const {
	int length = 0;
	while (str[length] != '\0') {
		++length;
	}
	return length;
}

std::ostream& KSerikov::operator << (std::ostream& os, const LongNumber& x) {
	if (x.length == 0) {
		os << "0";
	}
	else {
		if (x.sign == LongNumber::NEGATIVE) {
			os << '-';
		}
		for (int i = 0; i < x.length; ++i) {
			os << x.numbers[i];
		}
	}
	return os;
}

int main() {
	return 0;
}