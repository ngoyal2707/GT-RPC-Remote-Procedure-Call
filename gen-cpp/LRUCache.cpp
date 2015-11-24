#include "PageCache.h"
#include <iostream>
#include <cstdlib>

bool PageCache::getPage(const string &url, WebPage &webpage){
	std::tr1::unordered_map<string, ListNode *>::const_iterator it = this->hashMap.find(url);
	if(it!=this->hashMap.end()){
		ListNode * node = it->second;
		this->removeNode(node);
		this->addNode(node);
		webpage = node->webpage;
		return true;
	}else{
		return false;
	}
}
void PageCache::putPage(const string &url, WebPage &webpage){
	ListNode *node = new ListNode();
	node->url = url;
	node->webpage = webpage;
	this->hashMap[node->url] = node;
	this->addNode(node);

	queueSize += webpage.len; 
	queueEntries++;

	while(queueSize > MAX_SIZE){ // exclude some entries
		cout<<"Size exceeded, removing the LRU entry\n";
		ListNode *nodeToDelete = this->tail->prev;
		queueSize -= (nodeToDelete->webpage).len;
		queueEntries--;
		hashMap.erase(nodeToDelete->url);
		removeNode(nodeToDelete);
		if(nodeToDelete->prev != NULL){ 
		  free((nodeToDelete->webpage).data);
		  delete nodeToDelete; 
		}
  }

}
