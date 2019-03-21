#include <iostream>
#include <fstream>


#include "../pugixml-1.9/src/pugixml.hpp"

using namespace std;


string padded_number(long long n, int nb_0){
  string n_s = to_string(n);
  while(n_s.size() < 20){
    n_s = "0" + n_s;
  }
  return n_s;
}

int main()
{


  pugi::xml_document doc;
  long long nb_nodes = 1;
  doc.load_file("data/tree.xml");

  ofstream nodesf;
  nodesf.open("data/nodes_id.txt");

  nodesf << "                    \n"; //20 spaces for the total number of nodes

  pugi::xml_node node = doc.first_child().child("node");
  nodesf << node.attribute("id").value() << endl;

  while( (node = node.next_sibling()).name() == string("node")){
    nodesf << node.attribute("id").value() << endl;
    nb_nodes++;
  }

  nodesf.seekp(ios::beg);
  nodesf << padded_number(nb_nodes, 20);

  nodesf.close();

  cout << nb_nodes << endl;

}
