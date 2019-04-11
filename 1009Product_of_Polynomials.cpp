#include <iostream>
#include <iomanip>

using namespace std;

struct PolyNode {
	float coe;
	int exp;
	PolyNode *next;
};

struct Poly {
	int m_nNonzero;
	PolyNode *m_pHead;
	Poly() { m_nNonzero = 0; m_pHead = new PolyNode{-1,-1,nullptr}; }

	void clear() {									//free memmory
		PolyNode *p = m_pHead->next;
		PolyNode *q;
		while (p != nullptr) {
			q = p->next;
			delete p;
			p = q;
		}
	}

	void insert(float coe, int exp) {
		PolyNode *p;
		p = m_pHead->next;
		while (p != nullptr) {
			if (p->exp == exp) {					//the element with specified exponent exists
				p->coe += coe;						//change the coefficient
				break;
			}
			p = p->next;
		}

		if (p == nullptr) {
			p = m_pHead;
			while (p->next != nullptr) {			//the specified element dosen't exist
				if (p->next->exp < exp) break;		//find the element should be previous
				p = p->next;
			}
			PolyNode *pNew = new PolyNode{ coe,exp,nullptr };
			pNew->next = p->next;
			p->next = pNew;
			m_nNonzero++;
		}
	}
};

istream& operator>>(istream &is, Poly& poly) {
	is >> poly.m_nNonzero;
	if (poly.m_nNonzero != 0) {
		float fCoe;
		int nExp;
		PolyNode *q = poly.m_pHead;
		for (int i = 0; i < poly.m_nNonzero; i++) {
			is >> nExp >> fCoe;
			q->next = new PolyNode{ fCoe,nExp,nullptr };
			q = q->next;
		}
	}
	return is;
}

Poly operator*(Poly &A, Poly &B) {
	Poly res;

	PolyNode *pA = A.m_pHead->next;
	PolyNode *pB = B.m_pHead->next;

	while (pA != nullptr) {
		pB = B.m_pHead->next;
		while (pB != nullptr) {
			float coe = pA->coe * pB->coe;
			int exp = pA->exp + pB->exp;
			if(coe!=0) res.insert(coe, exp);
			pB = pB->next;
		}
		pA = pA->next;
	}
	return res;
}

ostream& operator<<(ostream &os, Poly &poly) {
	os << poly.m_nNonzero;
	PolyNode *p = poly.m_pHead->next;
	while (p != nullptr) {
		os << " " << p->exp << " ";
		os << setiosflags(ostream::fixed) << setprecision(1) << p->coe;
		p = p->next;
	}
	return os;
}

int main() {
	Poly A, B;
	cin >> A >> B;

	Poly res = A * B;

	cout << res << endl;

	A.clear();
	B.clear();
	return 0;
}