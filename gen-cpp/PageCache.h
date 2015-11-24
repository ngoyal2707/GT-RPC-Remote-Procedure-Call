#ifndef PAGE_CACHE_H
#define PAGE_CACHE_H

#include <vector>
#include <tr1/unordered_map>
#include <iostream>
#include <ctime>
#include <cstdlib>
// Keep the cache size 192 KB
#define MAX_SIZE (1<<20|1<<19)

using namespace std;

typedef struct WebPage{
  char *data;  // pointer to the webpage content
  size_t size; // allocated size
  size_t len;  // actual length of array
} WebPage;

typedef struct ListNode{
	ListNode *next;
	ListNode *prev;
	WebPage webpage;
	string url;
	int frequency;
}ListNode;

class PageCache
{
private:
	// Keep head and tail as extra pointers, 
	// will make life easier for further parts
	ListNode *head, *tail;
	std::tr1::unordered_map<string, ListNode *> hashMap;
	size_t queueSize;
	size_t queueEntries;
	
	// Would be helpful for random strategy
	vector<string> allURLs;

	// adds at the head
	void addNode(ListNode *node){
		node->next = head->next;
		head->next = node;
		node->prev = head;
		node->next->prev = node;
	}

	// removes the given node
	void removeNode(ListNode *node){
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
public:
	PageCache(){
		head = new ListNode();
		head->prev = head;

		tail = new ListNode();
		tail->prev = head;
		tail->next = NULL;
		head->next = tail;

		queueEntries = 0;
		queueSize = 0;

		srand(time(0));
	}
	~PageCache(){
		delete head;
		delete tail;
	}
	bool getPage(const string &url, WebPage &webpage);
	void putPage(const string &url, WebPage &webpage); 
};
#endif