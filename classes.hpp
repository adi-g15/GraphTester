struct ID_Creator {
	typedef uint16_t id_type;

	inline static id_type currID{ 10000 };

public:
	const atomic<id_type> id;
};
//ID_Creator 

struct Entity : ID_Creator {
	int id;
};

struct BoxObject {
public:
	std::string name;
	std::list<Entity*> entities;
	int id;

	BoxObject() : id(decltype(id){}) {}
	BoxObject(std::string&& s, decltype(entities) && entities, int id) : name(std::move(s)), entities(std::move(entities)), id(id) {}
	BoxObject(BoxObject&) = delete;
	BoxObject(BoxObject&& old_box) = default;
};