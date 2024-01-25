package getsetjob;

public class Job {

    String post, type, skill, empType, deadline;
    int vacancy;

    public Job(String post, String type, String skill, String empType, String deadline, int vacancy) {
        this.post = post;
        this.type = type;
        this.skill = skill;
        this.empType = empType;
        this.deadline = deadline;
        this.vacancy = vacancy;
    }
}
