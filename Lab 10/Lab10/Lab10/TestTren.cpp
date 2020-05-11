#include "TestTren.h"
#include <assert.h>
#include "Tren.h"
#include "Util.h"

void TestTren::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetModel();
	this->testSetModel();
	this->testGetProd();
	this->testSetProd();
	this->testGetLibere();
	this->testSetLibere();
	this->testGetOcup();
	this->testSetOcup();
	this->testSetNr();
	this->testGetNr();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void TestTren::testImplicitConstructor()
{
	Tren p;
	assert(p.getModel().empty());  assert(p.getProducator().empty());
	assert(p.getNr() == 0);
	assert(p.getLibere() == 0);
	assert(p.getOcupate() == 0);
}

void TestTren::testConstructorWithParameters()
{
	Tren p("CF","MODEL", 3,2,1);
	assert(p.getModel() == "CF");
	assert(p.getProducator() == "MODEL");
	assert(p.getNr() == 3);
	assert(p.getLibere() == 2);
	assert(p.getOcupate() == 1);
}

void TestTren::testCopyConstructor()
{
	Tren p1("CF", "MODEL", 3, 2, 1);
	Tren p2(p1);
	assert(p2.getModel() == p1.getModel());
	assert(p2.getProducator() == p1.getProducator());
	assert(p2.getNr() == p1.getNr());
	assert(p2.getLibere() == p1.getLibere());
	assert(p2.getOcupate() == p1.getOcupate());
}

void TestTren::testClone()
{
	Tren p("CF", "MODEL", 3, 2, 1);
	Tren* pClone = p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void TestTren::testGetModel()
{
	Tren p("CF", "MODEL", 3, 2, 1);
	assert(p.getModel() == "CF");
}

void TestTren::testSetModel()
{
	Tren p;
	p.setModel("banane");
	assert(p.getModel() == "banane");
}

void TestTren::testGetProd()
{
	Tren p("CF", "MODEL", 3, 2, 1);
	assert(p.getProducator() == "MODEL");
}

void TestTren::testSetProd()
{
	Tren p;
	p.setProducator("2");
	assert(p.getProducator() == "2");
}

void TestTren::testGetNr()
{
	Tren p("CF", "MODEL", 3, 2, 1);
	assert(p.getNr() == 3);
}
void TestTren::testSetNr()
{
	Tren p;
	p.setNrVag(2);
	assert(p.getNr() == 2);
}
void TestTren::testGetLibere()
{
	Tren p("CF", "MODEL", 3, 2, 1);
	assert(p.getLibere() == 2);
}
void TestTren::testGetOcup()
{
	Tren p("CF", "MODEL", 3, 2, 1);
	assert(p.getOcupate() == 1);
}
void TestTren::testSetOcup()
{
	Tren p;
	p.setOcupate(2);
	assert(p.getOcupate() == 2);
}
void TestTren::testSetLibere()
{
	Tren p;
	p.setLibere(2);
	assert(p.getLibere() == 2);
}
void TestTren::testAssignmentOperator()
{
	Tren p1("CF", "MODEL", 3, 2, 1);
	Tren p2;
	p2 = p1;
	assert(p2.getModel() == p1.getModel());
	assert(p2.getProducator() == p1.getProducator());
	assert(p2.getNr() == p1.getNr());
	assert(p2.getLibere() == p1.getLibere());
	assert(p2.getOcupate() == p1.getOcupate());
}

void TestTren::testEqualityOperator()
{
	Tren p1("CF", "MODEL", 3, 2, 1);
	Tren p2 = p1;
	assert(p1 == p2);
	p2.setModel("bruosa");
	assert(!(p1 == p2));
	p2.setModel(p1.getModel());
	assert(p1 == p2);
	p2.setProducator("pr");
	assert(!(p1 == p2));
	p2.setProducator(p1.getProducator());
	assert(p1 == p2);
	p2.setNrVag(4);
	assert(!(p1 == p2));
	p2.setNrVag(p1.getNr());
	assert(p1 == p2);
	p2.setOcupate(4);
	assert(!(p1 == p2));
	p2.setOcupate(p1.getOcupate());
	assert(p1 == p2);
	p2.setLibere(4);
	assert(!(p1 == p2));
	p2.setLibere(p1.getLibere());
	assert(p1 == p2);

}

void TestTren::testToString()
{
	Tren p1("CF", "MODEL", 3, 2, 1);
	assert(p1.toString(" ") == "CF MODEL 3 2 1");
	assert(p1.toString(",") == "CF,MODEL,3,2,1");
}
