#include "PageCache.h"
#include <iostream>
#include <cstdlib>


bool PageCache::getPage(const string &url, WebPage &webpage){
	std::tr1::unordered_map<string, ListNode *>::const_iterator it = this->hashMap.find(url);
	if(it!=this->hashMap.end()){
		ListNode * node = it->second;
		webpage = node->webpage;
		return true;
	}else{
		return false;
	}
}
void PageCache::putPage(const string &url, WebPage &webpage){
	// Page is too big to hold in cache
	if(webpage.len >= MAX_SIZE){
		return;
	}

	ListNode *node = new ListNode();
	node->url = url;
	node->webpage = webpage;
	queueSize += webpage.len; 
	
	while(queueSize > MAX_SIZE){ // exclude some entries
		cout<<"Size exceeded, removing the random entry, with queue size: "<<queueSize<<"\n";
		int randomURLIndex =  rand()%queueEntries;
		string randomURL = this->allURLs[randomURLIndex];

		ListNode *nodeToDelete = this->hashMap[randomURL];
		removeNode(nodeToDelete);
		queueSize -= (nodeToDelete->webpage).len;
		queueEntries--;
		
		if(nodeToDelete->prev != NULL){ 
		  free((nodeToDelete->webpage).data);
		  delete nodeToDelete; 
		}
		this->allURLs.erase(this->allURLs.begin()+randomURLIndex);
		this->hashMap.erase(randomURL);
  	}
  	this->hashMap[node->url] = node;
	this->allURLs.push_back(node->url);
	this->addNode(node);

	queueEntries++;
}
