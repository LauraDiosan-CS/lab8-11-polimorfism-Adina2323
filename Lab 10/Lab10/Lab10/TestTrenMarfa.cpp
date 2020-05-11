#include "TestTrenMarfa.h"
#include <assert.h>
#include "TrenMarfa.h"
#include "Util.h"

void TestTrenMarfa::testAll()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testGetMarfa();
	this->testSetMarfa();;
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testToString();
}

void  TestTrenMarfa::testImplicitConstructor()
{
	TrenMarfa p;
	assert(p.getModel().empty());  assert(p.getProducator().empty());
	assert(p.getNr() == 0);
	assert(p.getLibere() == 0);
	assert(p.getOcupate() == 0);
}

void  TestTrenMarfa::testConstructorWithParameters()
{
	TrenMarfa p("CF", "MODEL", 3,"marfa", 2, 1);
	assert(p.getModel() == "CF");
	assert(p.getProducator() == "MODEL");
	assert(p.getNr() == 3);
	assert(p.getLibere() == 2);
	assert(p.getOcupate() == 1);
}

void  TestTrenMarfa::testCopyConstructor()
{
	TrenMarfa p1("CF", "MODEL", 3, "marfa", 2, 1);
	TrenMarfa p2(p1);
	assert(p2.getModel() == p1.getModel());
	assert(p2.getProducator() == p1.getProducator());
	assert(p2.getNr() == p1.getNr());
	assert(p2.getLibere() == p1.getLibere());
	assert(p2.getOcupate() == p1.getOcupate());
	assert(p2.getMarfa() == p1.getMarfa());
}

void  TestTrenMarfa::testClone()
{
	TrenMarfa p("CF", "MODEL", 3, "marfa", 2, 1);
	TrenMarfa* pClone = (TrenMarfa*)p.clone();
	assert(p == *pClone);
	assert(&p != pClone);
}

void  TestTrenMarfa::testGetMarfa()
{
	TrenMarfa p("CF", "MODEL", 3, "marfa", 2, 1);
	assert(p.getMarfa() == "marfa");
}

void  TestTrenMarfa::testSetMarfa()
{
	TrenMarfa p("CF", "MODEL", 3, "marfa", 2, 1);
	p.setMarfa("banane");
	assert(p.getMarfa() == "banane");
}

void  TestTrenMarfa::testAssignmentOperator()
{
	TrenMarfa p1("CF", "MODEL", 3, "marfa", 2, 1);
	TrenMarfa p2(p1);
	assert(p2.getModel() == p1.getModel());
	assert(p2.getProducator() == p1.getProducator());
	assert(p2.getNr() == p1.getNr());
	assert(p2.getLibere() == p1.getLibere());
	assert(p2.getOcupate() == p1.getOcupate());
	assert(p2.getMarfa() == p1.getMarfa());
}

void  TestTrenMarfa::testEqualityOperator()
{
	TrenMarfa p1("CF", "MODEL", 3,"marfa", 2, 1);
	TrenMarfa p2 = p1;
	assert(p1 == p2);
	p2.setModel("bruosa");
	assert(!(p1 == p2));
	p2.setModel(p1.getModel());
	assert(p1 == p2);
	p2.setProducator("pr");
	assert(!(p1 == p2));
	p2.setProducator(p1.getProducator());
	assert(p1 == p2);
	p2.setNrVag(44);
	assert(!(p1 == p2));
	p2.setNrVag(p1.getNr());
	assert(p1 == p2);
	p2.setOcupate(44);
	assert(!(p1 == p2));
	p2.setOcupate(p1.getOcupate());
	assert(p1 == p2);
	p2.setLibere(44);
	assert(!(p1 == p2));
	p2.setLibere(p1.getLibere());
	assert(p1 == p2);
	p2.setMarfa("3");
	assert(!(p1 == p2));
	p2.setMarfa(p1.getMarfa());
	assert(p1 == p2);

}

void  TestTrenMarfa::testToString()
{
	TrenMarfa p1("CF", "MODEL", 3, "marfa", 2, 1);
	assert(p1.toString(" ") == "TM CF MODEL 3 2 1 marfa");
	assert(p1.toString(",") == "TM,CF,MODEL,3,2,1,marfa");
}
