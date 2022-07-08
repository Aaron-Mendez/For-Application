/*
    This is an addon to the decorator class that can be added
 */
/**
 *
 * @author aaron
 */
public class glamourTour extends addOn {

    public glamourTour(Tour newTour)
    {
        super(newTour);
    }
    @Override
    public String getDescription()
    {
        return tempTour.getDescription() + " A tour of glamorous period costumes";
    }
    
    @Override
    public double getCost()
    {
        return tempTour.getCost() + 45;
    } 
    
    @Override
    public int getMinTimeInMinutes()
    {
        return tempTour.getMinTimeInMinutes() + 90;
    }
}
