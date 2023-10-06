//
//  ASTree.cpp
//  Abstract Syntax Tree
//
//  Created by Jonathan Maletic
//  Copyright 2023 Kent State University. All rights reserved.
//  Spring 2023
//  srcML 1.0
//
//  Modified by:
//
//

#include "ASTree.hpp"


// Copy constructor for srcML
//
srcML::srcML(const srcML& actual) {
    header = actual.header; //sets header of the new object being created to the same as actuals header
    if (actual.tree)// if the member tree of actual is pointing to a valid object
        tree   = new AST(*(actual.tree));// it creates a new object of type AST using the copy constructor of AST passing the tree member of actual
    else                                //object as an argument and is stored on the heap using "new" and its address is stored in tree member of the new srcml obj.
        tree = 0;//if the actual tree member is pointing to nothing it sets the tree member of srcml to null as well
}

// Constant time swap for srcML
//
void srcML::swap(srcML& b) {
    std::string t_header = header;
    header = b.header;
    b.header = t_header;
    
    AST *temp = tree;
    tree = b.tree;
    b.tree = temp;
}

// Assignment for srcML
//
srcML& srcML::operator=(srcML rhs) {
    swap(rhs);
    return *this;
}

// Reads in and constructs a srcML object.
//
std::istream& operator>>(std::istream& in, srcML& src){
    char ch;
    if (!in.eof()) in >> ch;
    src.header = readUntil(in, '>');
    if (!in.eof()) in >> ch;
    if (src.tree) delete src.tree;
    src.tree = new AST(category, readUntil(in, '>'));
    src.tree->read(in);
    return in;
}

// Prints out a srcML object
//
std::ostream& operator<<(std::ostream& out, const srcML& src){
    if (src.tree) src.tree->print(out);
    return out;
}

//  Adds in the includes and profile object declarations
//
void srcML::mainHeader(const std::vector<std::string>& profileName,
                       const std::vector<std::string>& fileName    ) {
    tree->mainHeader(profileName, fileName);
}

//  Adds in the includes and declares profile object declarations
//
void srcML::fileHeader(const std::string& profileName) {
    tree->fileHeader(profileName);
}

// Adds in the report to the main
//
void srcML::mainReport(const std::vector<std::string>& profileName) {
        tree->mainReport(profileName);
}

///  Inserts a profile.count() into each function body.
//
void srcML::functionCount(const std::string& profileName) {
    tree->functionCount(profileName);
}

// Inserts a profile.count() for each statement.
//
void srcML::lineCount(const std::string& profileName) {
    tree->lineCount(profileName);
}

    

//
//AST::
//


// Constructs a category, token, or whitespace node for the tree.
//
AST::AST(nodes t, const std::string& s) {
    nodeType = t;
    switch (nodeType) {
        case category:
            tag = s;
            break;
        case token:
            text = unEscape(s);
            break;
        case whitespace:
            text = s;
            break;
    }
}


// Destructor for AST
//
AST::~AST() {
    //TODO: IMPLEMENT
    //Recursively traverse tree and delete from bottom up
    std::list<AST*>::const_iterator itr = child.begin(); //create a list that will store all the children
    
    while (itr != child.end()){ //loop as long as we are not at the end of the tree
    if(!child.empty()) //make sure the deletion only takes place if child is not empty
        delete *itr++;

    }
}


// Copy Constructor for AST
//
AST::AST(const AST& actual) {
    //TODO: IMPLEMENT
    //Recursively traverse actual and
    //make a copy of each node putting it
    //into this.

//need to copy all the private members
    nodeType = actual.nodeType;
    tag = actual.tag;
    closeTag = actual.closeTag;
    text = actual.text;

//now copying all the children into the new tree
    std::list<AST*>::const_iterator itr = actual.child.begin(); //adding all the children from the old tree and storing them in the list
    while(itr != actual.child.end()){ //while you are not at the end of the old Trees children
        child.push_back(new AST(**itr)); //push_back the children recursively one by one on to the new tree
        ++itr; //increment the iterator 
    }
}


// Constant time swap for AST
//
void AST::swap(AST& rhs) {
    //TODO: IMPLEMENT
    //Swap all the top level childern (pointers to AST)

    nodes tempNode = rhs.nodeType;
    rhs.nodeType = nodeType;
    nodeType = tempNode;

    std::string tempTag = rhs.tag;
    rhs.tag = tag;
    tag = tempTag;

    std::string tempText = rhs.text;
    rhs.text = text;
    text = tempText;

    std::string tempCloseTag = rhs.closeTag;
    rhs.closeTag = closeTag;
    closeTag = tempCloseTag;

    child.swap(rhs.child);


}

/// Assignment for AST
//
AST& AST::operator=(AST rhs) {
    swap(rhs);
    return *this;
}


// REQUIRES: this->nodetype == category && tagName is valid srcML tag
// ENSURES: RETVAL == this->child[i] where this->child[i]->tag == tagName
//
// IMPORTANT for milestone 2 and 3
//
AST* AST::getChild(std::string tagName) {
    std::list<AST*>::iterator ptr = child.begin();
    while (((*ptr)->tag != tagName) && (ptr != child.end())) {
         ++ptr;
    }
    return *ptr;
}


// REQUIRES: this->tag == "name"
// Returns the full name of a <name> node
//  There are two types of names in srcML.  A simple name (e.g., foo) and a
//   name with a scope (e.g., std::bar).  This returns the correct
//   one from <name> AST node.
//
// IMPORTANT for milestone 3
//
std::string AST::getName() const {
    std::string result;
    if (child.front()->tag != "name") {
        result = child.front()->text;   //A simple name (e.g., main)
    } else {                            //A complex name (e.g., stack::push).
        result = child.front()->child.front()->text;
        result += "::";
        result += child.back()->child.front()->text;
    }
    return result;
}


//  Adds above the main, in the main file:
//  1. #include "profile.hpp"
//  2. All needed profile object declarations
//      example: profile foo_cpp("foo.cpp");
//
void AST::mainHeader(const std::vector<std::string>& profileName,
                     const std::vector<std::string>& fileName     ) {
    //TODO: IMPLEMENT
    //Skip down a couple lines or find main and put it before it
    //Add a node with #include "profile.hpp"
    //For each file profile name, add a node with a profile
    //   declaration "profile foo_cpp("foo.cpp");"

    std::string profHeader = "#include \"profile.hpp\""; // a string that will be holding the needed implementation
    std::list<AST*>::iterator obj = child.begin(); //an iterator that starts at the first node
    while((*obj)->tag != "function"){//loop as long as obj->tag != function
        ++obj; //increment the iterator
    }
    child.insert(obj, new AST(token, profHeader)); //doing a child insert of the implementation needed

    std::vector<std::string>::const_iterator it = profileName.begin();
    std::vector<std::string>::const_iterator itr = fileName.begin();

    while(it != profileName.end()){
        profHeader = "\nprofile " + (*it) + "(\"" + (*itr) + "\")" + ";\n""\n";
        child.insert(obj, new AST(token, profHeader));
        ++itr;
        ++it;
    }
}


//  Adds in each file (except main file):
//  1. #include "profile.hpp"
//  2. All needed external profile object declarations
//      example: extern profile thisfile_cpp;
//
void AST::fileHeader(const std::string& profileName) {

    //TODO: IMPLEMENT
    //Skip down a couple lines or find first function and put it before it
    //Add #include "profile.hpp"
    //Add in the external declaration for that file "extern profile foo_cpp;"

    std::list<AST*>::iterator obj = child.begin();
    while((*obj)->tag != "function"){ //loop as long as obj dereferenced pointing at(->) tag is not "function"
        ++obj;
    }

    std::string profString = "#include \"profile.hpp\""; //String that is holding the include header
    profString = profString + "\nextern profile" + profileName + ";\n""\n"; //puts it on a new line and appends a ';'
    child.insert(obj, new AST(token, profString)); //insert the child with parameters


}


// Adds in the report to the main file
// Assumes only one return in the main
//
void AST::mainReport(const std::vector<std::string>& profileName) {
    
    //TODO: IMPLEMENT
    //Find the function with name of "main" in the file
    // -Get the "block" node of this function
    // -Set an iterator to the child.end() of "block"
    // -Decrement it once (to skip the "}")
    // -Search backwards for a "return" tag
    // -Insert the report statements before the return

std::list<AST*>::iterator it = child.begin();
    while(it != child.end()){
        if(((*it)->tag == "function") && ((*it)->getChild("name")->getName() == "main")){
            AST *block = (*it)->getChild("block")->getChild("block_content");

            
            std::list<AST*>::iterator itrBlock = block->child.begin();
            while((*itrBlock)->tag != "return"){
                ++itrBlock;
            }
            --itrBlock;

            AST *output = new AST(token);
            std::string outputCode;
            for(std::vector<std::string>::const_iterator i = profileName.begin(); i != profileName.end(); ++i){
                outputCode = outputCode + ("std::cout<< " + (*i) + " << std::endl; \n");
            }
            output->text = outputCode;
            block->child.insert(itrBlock, output);
        }
        ++it;
    }


}


// Adds a node to the function block to count the times each function
//  is executed
//  Assumes no nested functions
//
void AST::functionCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // for each child in the "unit"
    //     if child is a function, constructor, destructor
    //        Find the function name (use AST::getName())
    //        Find <block>, then find <block_content>
    //        Insert the count as first child in <block_content>
    //        Example: main1_cpp.count(__LINE__, "main");

        std::list<AST*>::iterator it = child.begin();
  
    while(it != child.end()){
          std::string currentTag = (*it)->tag;
        if(currentTag == "function" || currentTag == "constructor" || currentTag == "destructor"){
            
            AST *block = (*it)->getChild("block");
            AST *name      = (*it)->getChild("name");
            AST *frontChild = name->child.front();
            
            std::string funcName = frontChild->text;
            std::string codeCount = " " + profileName + ".count(__LINE__, \"" + funcName + "\"); \n";

            AST *count = new AST(token);
            count->text = codeCount;

            std::list<AST*>::iterator itrBlock = block->child.begin();
            while((*itrBlock)->text != "{"){
                ++itrBlock;
            }
            ++itrBlock;
            block->child.insert(itrBlock, count);
        }
        ++it;
    }

}


// Adds in a node to count the number of times each statement is executed
//   Do not count breaks, returns, throw, declarations, etc.
//   Assumes all construts (for, while, if) have an explicit block { }
//
void AST::lineCount(const std::string& profileName) {
    
    //TODO: IMPLEMENT
    // Recursively check for expr_stmt within all category nodes <block>
    // Very similar to AST::print
    // For each child:
    //   If it is a category node
    //       If it is a expr_stmt insert a count after it
    //          Example: foo_cpp.count(__LINE__);
    //       Else call lineCount if not a stop tag  See isStopTag()
    //   Else (token or whitespace) do nothing

    std::string countLines = (" " + profileName + ".count(__LINE__); \n");
    std::list<AST*>::iterator itr = child.begin();

    while(itr != child.end()){
        if(!(*itr)->child.empty())
        (*itr)->lineCount(profileName);

        if((*itr)->tag == "expr_stmt"){
            AST *count = new AST(token);
            count->text = countLines;
            (*itr)->child.push_back(count);
        }
        ++itr;
    }
    
}

// Returns TRUE if the tag (syntactic category) is not to be profiled
//
// IMPORTANT for milestone 3
//
bool isStopTag(std::string tag) {
    if (tag == "condition"             ) return true; //Remove for challenge
    if (tag == "type"                  ) return true;
    if (tag == "name"                  ) return true;
    if (tag == "return"                ) return true;
    if (tag == "break"                 ) return true;
    if (tag == "continue"              ) return true;
    if (tag == "parameter_list"        ) return true;
    if (tag == "decl_stmt"             ) return true;
    if (tag == "argument_list"         ) return true;
    if (tag == "init"                  ) return true;
    if (tag == "cpp:include"           ) return true;
    if (tag == "macro"                 ) return true;
    if (tag == "comment type=\"block\"") return true;
    if (tag == "comment type=\"line\"" ) return true;
    return false;
}


// Print an AST
// Preorder traversal that prints out leaf nodes only (tokens & whitesapce)
//
std::ostream& AST::print(std::ostream& out) const {
    for (std::list<AST*>::const_iterator i = child.begin(); i != child.end(); ++i) {
        if ((*i)->nodeType != category)
            out << (*i)->text;   //Token or whitespace node, print it
        else
            (*i)->print(out);    //Category node, recursive call
    }
    return out;
}


// Read in and construct AST
// REQUIRES: '>' was previous charater read 
//           && this == new AST(category, "TagName")
//
std::istream& AST::read(std::istream& in) {
    AST *subtree;
    std::string temp, Lws, Rws;
    char ch;
    if (!in.eof()) in.get(ch);
    while (!in.eof()) {
        if (ch == '<') {                      //Found a tag
            temp = readUntil(in, '>');
            if (temp[0] == '/') {
                closeTag = temp;
                break;                        //Found close tag, stop recursion
            }
            subtree = new AST(category, temp);               //New subtree
            subtree->read(in);                               //Read it in
            in.get(ch);
            child.push_back(subtree);                        //Add it to child
        } else {                                             //Found a token
            temp = std::string(1, ch) + readUntil(in, '<');  //Read it in.
            std::vector<std::string> tokenList = tokenize(temp);
            for (std::vector<std::string>::const_iterator i=tokenList.begin();
                 i != tokenList.end();
                 ++i) {
                if (isspace((*i)[0])) {
                    subtree = new AST(whitespace, *i);
                } else {
                    subtree = new AST(token, *i);
                }
                child.push_back(subtree);
            }
            ch = '<';
        }
    }
    return in;
}



// Utilities for AST::read()

// Reads until a key is encountered.  Does not include ch.
// REQUIRES: in.open()
// ENSURES: RetVal[i] != key for all i.
std::string readUntil(std::istream& in, char key) {
    std::string result;
    char ch;
    in.get(ch);
    while (!in.eof() && (ch != key)) {
        result += ch;
        in.get(ch);
    }
    return result;
}

// Converts escaped XML charaters back to charater form
// REQUIRES: s == "&lt;"
// ENSURES:  RetVal == "<"
std::string unEscape(std::string s) {
    std::size_t pos = 0;
    while ((pos = s.find("&gt;"))  != s.npos) { s.replace(pos, 4, ">"); }
    while ((pos = s.find("&lt;"))  != s.npos) { s.replace(pos, 4, "<"); }
    while ((pos = s.find("&amp;")) != s.npos) { s.replace(pos, 5, "&"); }
    return s;
}

// Given: s == "   a + c  "
// RetVal == {"   ", "a", " ", "+", "c", " "}
std::vector<std::string> tokenize(const std::string& s) {
    std::vector<std::string> result;
    std::string temp = "";
    unsigned i = 0;
    while (i < s.length()) {
        while (isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
        while (!isspace(s[i]) && (i < s.length())) {
            temp.push_back(s[i]);
            ++i;
        }
        if (temp != "") {
            result.push_back(temp);
            temp = "";
        }
    }
    return result;
}
    

