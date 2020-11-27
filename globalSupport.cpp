#include "globalSupport.h"

void Semantics::checkDec(Token tk){
    int isDec = -1;
    for(unsigned int i = 0; i < st.size(); i++){
        if(st[i].id.val == tk.val){
            isDec = i;
            break;
        }
    }

    if(isDec > -1){
        cout << "SEMANTICS ERROR: Varable: " << tk.val << " on line " << tk.lineNum << " was already declared on line " << st[isDec].id.lineNum << endl;
    }else{
        holder.id = tk;
        st.push_back(holder);
    }
}

void Semantics::checkDef(Token tk){
    int isDef = -1;

    for(unsigned int i = 0; i < st.size(); i++){
        if(st[i].id.val == tk.val){
            isDef = i;
            break;
        }
    }

    if(isDef < 0){
        cout << "SEMANTICS ERROR: Variable: " << tk.val << " on line: " << tk.lineNum << " is not defined or declared on the stack yet" << endl;
        exit(EXIT_FAILURE);
    }
}

void Semantics::valid(Node* node){
    if(node == NULL){
        return;
    }

    if(node->name == "<vars>"){
        for(unsigned int i = 0; i < node->tokens.size(); i++){
            if(node->tokens[i].id == idTK && node->tokens[i].val != "EMPTY"){
                checkDec(node->tokens[i]);
            }
        }
    }else{
        vector<string> names = {"<R>", "<assign>"};
        for(unsigned int i = 0; i < names.size(); i++){
            if(node->name == names[i]){
                for(unsigned int j = 0; j < node->tokens.size(); j++){
                    if(node->tokens[j].id == idTK){
                        checkDef(node->tokens[j]);
                    }
                }
            }
        }
    }

    valid(node->n1);
    valid(node->n2);
    valid(node->n3);
    valid(node->n4);
}