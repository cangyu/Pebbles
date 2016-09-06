#ifndef SVGCONTAINERELEMENT_H
#define SVGCONTAINERELEMENT_H

#include <map>
#include <list>
#include "SVGElement.h"

class SVGContainerElement : public SVGElement{
    typedef std::list<SVGElement*> ElementList;
    typedef std::map<std::string, ElementList::iterator> IDMap;
    typedef std::list<SVGContainerElement*> CElementList;
    typedef std::map<std::string, CElementList::iterator> CIDMap;
    ElementList elements;
    IDMap id2elm; // id -> element
    CElementList celements;
    CIDMap cid2elm; // id -> container element

protected:
	// Constructor
	SVGContainerElement(const std::string &_tag, const std::string &_id) : SVGElement(_tag, _id) {}

    std::ostream& print_body(std::ostream& out) const {
        // Print the elements
		for (ElementList::const_iterator iter = elements.begin(); iter != elements.end(); iter++)
			(*iter)->print(out);
        return out;
    }

    /* call `add` to clone body from `from` */
    void clone_body_from(const SVGContainerElement& from) {
        ElementList::const_iterator ei = from.elements.begin();
        ElementList::const_iterator ee = from.elements.end();
        CElementList::const_iterator ci = from.celements.begin();
        CElementList::const_iterator ce = from.celements.end();
        for (; ei != ee; ++ei) {
            if (ci == ce || *ei != *ci) {// the element may be a container,handle the case
				add(**ei);
            } else {
				add(**ci);
				ci++;
            }
        }
    }

    virtual std::ostream& print_tag_close(std::ostream& out) const {
        out << "</" << tag << ">" << std::endl;
        return out;
    }

private:
    void add_element(SVGElement* e) {
        ElementList::iterator iter = elements.insert(elements.end(), e);
        const std::string id = e->getID();
        if (!id.empty()) {
            id2elm[id] = iter;
        }
    }

public:
    void add(const SVGContainerElement& elm) {
        SVGContainerElement* e = elm.clone_as_container();
        CElementList::iterator iter = celements.insert(celements.end(), e);
        if (!e->getID().empty()) {
            cid2elm[elm.getID()] = iter;
        }

        add_element(e);//用派生类来初始化基类元素，同样放在element里面
    }

    void add(const SVGElement& elm) {
		add_element(elm.clone());
    }

    SVGContainerElement& findContainer(const std::string& id) {
        CIDMap::iterator iter = cid2elm.find(id);
        if (iter == cid2elm.end()) {
            throw "element not found";
        }
        return **iter->second;
    }

    void remove(const std::string& id) {
        IDMap::iterator iter = id2elm.find(id);
        if (iter == id2elm.end()) {
            throw "element not found";
        }
        
		// Remove operation as an element
		delete *iter->second;//free the related object, must do this first,otherwise,the later erase operation will change the iter
		elements.erase(iter->second);//remove record in list
		id2elm.erase(iter);//remove record in map
		

        CIDMap::iterator iter2 = cid2elm.find(id);
        if (iter2 != cid2elm.end()) {
            celements.erase(iter2->second);
            cid2elm.erase(iter2);
        }
    }

    virtual SVGContainerElement* clone_as_container() const = 0;

    virtual ~SVGContainerElement() {
        // Free all the elements,recursively free all?
		for (ElementList::const_iterator iter = elements.begin(); iter != elements.end(); iter++)
			delete *iter;
    }
};

#endif

